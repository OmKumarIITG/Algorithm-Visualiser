#include <SDL2/SDL.h>
#include <bits/stdc++.h>
using namespace std;

const int WIDTH_WINDOW = 500;
const int HEIGHT_WINDOW = 500;
const int SCALE_X = WIDTH_WINDOW / 20;
const int SCALE_Y = HEIGHT_WINDOW / 20;

void showStateGraph(vector<vector<int>> &grid, vector<vector<int>> &vis, SDL_Renderer *renderer)
{

    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else
            {
                // means no obstacle
                if (vis[i][j] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                }
                else
                {
                    // if visited mark blue
                    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                }
            }
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
}

void showStateVector(vector<int> &v, SDL_Renderer *renderer, int l, int r)
{

    int n = v.size();
    // set render color for all elements of vector
    for (int i = 0; i < n; i++)
    {
        if (i == l)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
        else if (i == r)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        }
        SDL_RenderDrawLine(renderer, i, HEIGHT_WINDOW / SCALE_Y, i, HEIGHT_WINDOW / SCALE_Y - v[i]);
    }
}

void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, SDL_Renderer *renderer)
{
    vis[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int n = grid.size();
    int m = grid[0].size();
    showStateGraph(grid, vis, renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);

    for (int i = 0; i < 4; i++)
    {
        int p = x + dx[i];
        int q = y + dy[i];
        if (p >= 0 && p < n && q >= 0 && q < m && vis[p][q] == 0 && grid[p][q] == 0)
        {
            dfs(p, q, grid, vis, renderer);
        }
    }
}

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, SDL_Renderer *renderer)
{
    queue<pair<int, int>> queue;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int n = grid.size();
    int m = grid[0].size();
    queue.push({0, 0});
    vis[0][0] = 1;
    while (!queue.empty())
    {
        auto it = queue.front();
        queue.pop();
        int x = it.first;
        int y = it.second;
        for (int i = 0; i < 4; i++)
        {
            int p = x + dx[i];
            int q = y + dy[i];
            if (p >= 0 && p < n && q >= 0 && q < m && vis[p][q] == 0 && grid[p][q] == 0)
            {
                vis[p][q] = 1;
                queue.push({p, q});
                showStateGraph(grid, vis, renderer);
                SDL_RenderPresent(renderer);
                SDL_Delay(100);
            }
        }
    }
}

void dijkstra(vector<vector<int>> &grid, vector<vector<int>> &vis, SDL_Renderer *renderer)
{
}

void bubbleSort(vector<int> &v, SDL_Renderer *renderer)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white background
            SDL_RenderClear(renderer);
            showStateVector(v, renderer, j, j + 1);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
}

void merge(vector<int> &v, int left, int mid, int right, SDL_Renderer *renderer)
{
    vector<int> temp(v.size());
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = v[i++];
    }

    while (j <= right)
    {
        temp[k++] = v[j++];
    }

    for (int i = left; i <= right; i++)
    {
        v[i] = temp[i];
    }

    // Visualization
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white background
    SDL_RenderClear(renderer);
    showStateVector(v, renderer, -1, -1); // Update the vector display
    SDL_RenderPresent(renderer);
    SDL_Delay(100); // Delay to visualize the merge step
}

void mergeSortRec(vector<int> &v, int left, int right, SDL_Renderer *renderer)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSortRec(v, left, mid, renderer);
        mergeSortRec(v, mid + 1, right, renderer);

        // Merge the sorted halves
        merge(v, left, mid, right, renderer);
    }
}

void mergeSort(vector<int> &v, SDL_Renderer *renderer)
{
    mergeSortRec(v, 0, v.size() - 1, renderer);
}

int partitioning(vector<int> &v, int low, int high, SDL_Renderer *renderer)
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White background
        SDL_RenderClear(renderer);
        showStateVector(v, renderer, i, j);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    swap(v[i + 1], v[high]);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White background
    SDL_RenderClear(renderer);
    showStateVector(v, renderer, i + 1, high); // Highlight the pivot swap
    SDL_RenderPresent(renderer);
    SDL_Delay(100);

    return i + 1;
}

void quickSort(vector<int> &v, int low, int high, SDL_Renderer *renderer)
{
    if (low < high)
    {
        int p = partitioning(v, low, high, renderer);
        quickSort(v, low, p - 1, renderer);
        quickSort(v, p + 1, high, renderer);
    }
}

void reset(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &v)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = rand() % 2;
            vis[i][j] = 0;
        }
    }

    int max_value = HEIGHT_WINDOW / SCALE_Y;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = rand() % (max_value);
    }
}

int main(int arg, char **argc)
{

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH_WINDOW, HEIGHT_WINDOW, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, SCALE_X, SCALE_Y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // GRAPH
    int N = 20;
    vector<vector<int>> grid(N, vector<int>(N, 0));
    vector<vector<int>> vis(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // SORTING
    vector<int> numbers(N);
    int max_value = HEIGHT_WINDOW / SCALE_Y;
    for (int i = 0; i < N; i++)
    {
        numbers[i] = rand() % (max_value);
    }

    SDL_Event e;
    bool running = true;\

    bool sorted = false; // Track if sorting is completed
    bool resetted = true;
    bool isGraphAlgo = true;

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                int x = mouseX / SCALE_X;
                int y = mouseY / SCALE_Y;

                grid[x][y] ^= 1;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_1: // Reset
                    cout<<"1 pressed\n";
                    cout << "RESETTED DISPLAY\n";
                    SDL_RenderClear(renderer);
                    reset(grid, vis, numbers);
                    sorted = false;
                    resetted = true;
                    break;
                case SDLK_4: // Bubble Sort
                    cout<<"4 pressed\n";
                    cout << "BUBBLE_SORT_STARTED\n";
                    if (!sorted)
                    {
                        bubbleSort(numbers, renderer);
                        sorted = true;
                    }
                    cout << "BUBBLE_SORT_FINISHED\n";
                    resetted = false;
                    isGraphAlgo = false;
                    break;
                case SDLK_5: // Merge Sort
                    cout<<"5 pressed\n";
                    cout << "MERGE_SORT_STARTED\n";
                    if (!sorted)
                    {
                        mergeSort(numbers, renderer);
                        sorted = true;
                    }
                    cout << "MERGE_SORT_FINISHED\n";
                    resetted = false;
                    isGraphAlgo = false;
                    break;
                case SDLK_6: // Quick Sort
                    cout<<"6 pressed\n";
                    cout << "QUICK_SORT_STARTED\n";
                    if (!sorted)
                    {
                        quickSort(numbers, 0, numbers.size() - 1, renderer);
                        sorted = true;
                    }
                    cout << "QUICK_SORT_FINISHED\n";
                    resetted = false;
                    isGraphAlgo = false;
                    break;
                case SDLK_3: // BFS
                    cout<<"3 pressed\n";
                    cout << "BFS_STARTED\n";
                    bfs(grid, vis, renderer);
                    cout << "BFS_FINISHED\n";
                    resetted = false;
                    isGraphAlgo = true;
                    break;
                case SDLK_2: // DFS
                    cout<<"2 pressed\n";
                    cout << "DFS_STARTED\n";
                    dfs(0, 0, grid, vis, renderer);
                    cout << "DFS_FINISHED\n";
                    resetted = false;
                    isGraphAlgo = true;
                    break;
                }
            }
        }
        if (resetted)
        {
            if (isGraphAlgo)
                showStateGraph(grid, vis, renderer);
            else
                showStateVector(numbers, renderer, -1, -1);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}