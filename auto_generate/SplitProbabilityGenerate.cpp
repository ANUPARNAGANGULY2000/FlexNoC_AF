#include <vector>
#include <string>
enum Port { N = 0, S = 1, E = 2, W = 3, L = 4 };
static const int NUM_PORTS = 5;
Port getOutputPort(int r, int c, int nr, int nc) {
    if (nr == r - 1 && nc == c) return N;
    if (nr == r + 1 && nc == c) return S;
    if (nr == r && nc == c + 1) return E;
    if (nr == r && nc == c - 1) return W;
    return L;
}

void nextHop(int r, int c, int dr, int dc,
             const std::string& routingAlgo,
             int& nr, int& nc) {

    nr = r;
    nc = c;

    if (routingAlgo == "YX") {
        if (r != dr)
            nr += (dr > r ? 1 : -1);
        else if (c != dc)
            nc += (dc > c ? 1 : -1);
    }
    else { // XY
        if (c != dc)
            nc += (dc > c ? 1 : -1);
        else if (r != dr)
            nr += (dr > r ? 1 : -1);
    }
}

std::vector<std::vector<std::vector<double>>>
Compute_Per_Router_Probability(int size,
                               const std::string& routingAlgo) {

    int totalRouters = size * size;

    // count[router][input][output]
    std::vector<std::vector<std::vector<int>>> count(
        totalRouters,
        std::vector<std::vector<int>>(NUM_PORTS,
            std::vector<int>(NUM_PORTS, 0))
    );

    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {

            int routerId = r * size + c;

            for (int in = 0; in < NUM_PORTS; ++in) {

                // Skip invalid physical ports
                if ((in == N && r == 0) ||
                    (in == S && r == size - 1) ||
                    (in == W && c == 0) ||
                    (in == E && c == size - 1))
                    continue;

                // All destinations (including itself)
                for (int dr = 0; dr < size; ++dr) {
                    for (int dc = 0; dc < size; ++dc) {

                        // Destination = this router → Local
                        if (dr == r && dc == c) {
                            count[routerId][in][L]++;
                            continue;
                        }

                        int nr, nc;
                        nextHop(r, c, dr, dc, routingAlgo, nr, nc);

                        Port out = getOutputPort(r, c, nr, nc);
                        count[routerId][in][out]++;
                    }
                }
            }
        }
    }

    // Normalize counts → probabilities
    std::vector<std::vector<std::vector<double>>> probability(
        totalRouters,
        std::vector<std::vector<double>>(NUM_PORTS,
            std::vector<double>(NUM_PORTS, 0.0))
    );

    for (int r = 0; r < totalRouters; ++r) {
        for (int in = 0; in < NUM_PORTS; ++in) {
            int total = 0;
            for (int out = 0; out < NUM_PORTS; ++out)
                total += count[r][in][out];

            if (total == 0) continue;

            for (int out = 0; out < NUM_PORTS; ++out)
                probability[r][in][out] =
                    static_cast<double>(count[r][in][out]) / total;
        }
    }

    return probability;
}







