#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Interval {
    ll start;
    ll end;
};

Interval intersect(Interval a, Interval b, ll N) {
    if (a.start == -1 || b.start == -1) return {-1, -1};

    auto normalize = [N](Interval x) {
        vector<pair<ll, ll>> parts;
        if (x.start <= x.end) {
            parts.emplace_back(x.start, x.end);
        } else {
            parts.emplace_back(x.start, N-1);
            parts.emplace_back(0, x.end);
        }
        return parts;
    };

    auto a_parts = normalize(a);
    auto b_parts = normalize(b);

    vector<pair<ll, ll>> intersections;
    for (auto &ap : a_parts) {
        for (auto &bp : b_parts) {
            ll s = max(ap.first, bp.first);
            ll e = min(ap.second, bp.second);
            if (s <= e) {
                intersections.emplace_back(s, e);
            }
        }
    }

    if (intersections.empty()) return {-1, -1};

    sort(intersections.begin(), intersections.end());
    ll merged_start = intersections[0].first;
    ll merged_end = intersections[0].second;

    for (size_t i = 1; i < intersections.size(); ++i) {
        ll current_start = intersections[i].first;
        ll current_end = intersections[i].second;
        if (current_start > merged_end + 1) {
            return {-1, -1};
        }
        merged_end = max(merged_end, current_end);
    }

    if (merged_start == 0 && merged_end == N-1) {
        return {0, N-1};
    }

    if (merged_start <= merged_end) {
        return {merged_start, merged_end};
    } else {
        return {merged_start, (merged_end + N) % N};
    }
}

ll calculate_size(Interval interval, ll N) {
    if (interval.start == -1) return 0;
    if (interval.start <= interval.end) {
        return interval.end - interval.start + 1;
    } else {
        return (N - interval.start) + interval.end + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> exps(M);
    for (ll i = 0; i < M; ++i) {
        cin >> exps[i].first >> exps[i].second;
    }

    Interval current = {0, N-1};
    ll R_prev = N;

    for (ll i = 0; i < M; ++i) {
        ll A = exps[i].first;
        ll B = exps[i].second;
        ll Si, Fi;

        if (i == 0) {
            Si = A;
            Fi = B;
        } else {
            Si = (R_prev + A) % N;
            Fi = (R_prev + B) % N;
        }

        Interval new_intv = {Si, Fi};
        current = intersect(current, new_intv, N);

        R_prev = calculate_size(current, N);
        cout << R_prev << '\n';
    }

    return 0;
}