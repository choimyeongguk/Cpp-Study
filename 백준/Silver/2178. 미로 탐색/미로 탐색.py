import queue

maze = []
R, C = map(int, input().split())
for i in range(0, R):
  maze.append(list(map(int, input())))

d = [[-1, 0], [1, 0], [0, -1], [0, 1]]
bfs = queue.Queue()
bfs.put([0, 0])
while(bfs.qsize() > 0):
  r, c = map(int, bfs.get())
  for i in range(0, 4):
    tr = r + d[i][0]
    tc = c + d[i][1]
    if(0 <= tr < R and 0 <= tc < C and maze[tr][tc] == 1):
      bfs.put([tr, tc])
      maze[tr][tc] = maze[r][c] + 1

print(maze[R-1][C-1])