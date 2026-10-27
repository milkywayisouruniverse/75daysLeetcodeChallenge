class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        d = min(m, n) - 1  # the fence: cells where row + column == d
        gate = (d, 0) if m <= n else (0, d)  # its only open cell is a corner, so both legs are straight lines
        return ["".join(".#"[i + j == d and (i, j) != gate] for j in range(n)) for i in range(m)]