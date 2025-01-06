#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song
{
    char songName[100];
    struct song *next;
};

const char *availableSongs[10] =
    {
        "Blinding Lights -- The Weeknd",
        "Thriller -- Michael Jackson",
        "WILDFLOWER -- Billie Eilish",
        "Pink Skies -- Zach Bryan",
        "Beautiful Things --  Benson Boone",
        "Too Sweet -- Hozier",
        "Burning Down -- Alex Warren",
        "Bohemian Rhapsody -- Queen",
        "Dancing Queen -- ABBA",
        "Last Flowers -- Radiohead"};

const int totalSongs = 10;

const char *chooseSongs(int option)
{
    switch (option)
    {
    case 1:
        return availableSongs[0];
        break;
    case 2:
        return availableSongs[1];
        break;
    case 3:
        return availableSongs[2];
        break;
    case 4:
        return availableSongs[3];
        break;
    case 5:
        return availableSongs[4];
        break;
    case 6:
        return availableSongs[5];
        break;
    case 7:
        return availableSongs[6];
        break;
    case 8:
        return availableSongs[7];
        break;
    case 9:
        return availableSongs[8];
        break;
    case 10:
        return availableSongs[9];
        break;
    default:
        return "Invalid\n";
    }
}

int isSongAvailable(const char *song)
{
    for (int i = 0; i < totalSongs; i++)
    {
        if (strcmp(song, availableSongs[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void displayAllSongs()
{
    printf("\nAvailable Songs:\n");
    for (int i = 0; i < totalSongs; i++)
    {
        printf("%d.%s \n", (i + 1), availableSongs[i]);
    }
    printf("\n");
}

int countSongs(struct song *head)
{
    int count = 0;
    struct song *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
struct song *createSongNode(const char *newSong)
{
    struct song *newNode = (struct song *)malloc(sizeof(struct song));
    strcpy(newNode->songName, newSong);
    newNode->next = NULL;
    return newNode;
}
void displayPlaylist(struct song *head)
{
    int i = 1;
    struct song *current = head;
    printf("\nCurrent Playlist:\n");
    while (current != NULL)
    {
        printf("Song %d: %s \n", i, current->songName);
        i++;
        current = current->next;
    }
}
struct song *addSong(struct song *head, const char *songName)
{
    struct song *newNode = createSongNode(songName);
    if (head == NULL)
        return newNode;

    struct song *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct song *insertSong(struct song *head, const char *songName, int position)
{
    position = position - 1;
    struct song *newNode = createSongNode(songName);
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    struct song *current = head;
    int i = 0;
    while (i < position - 1)
    {
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct song *removeSong(struct song *head, int position)
{
    position = position - 1;
    struct song *temp = NULL, *current = NULL, *prevNode = NULL;
    if (position == 0)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int i = 0;
    current = head;
    while (i < position)
    {
        prevNode = current;
        current = current->next;
        i++;
    }
    prevNode->next = current->next;
    free(current);
    return head;
}

struct song *shufflePlaylist(struct song *head)
{
    int n = countSongs(head);
    struct song *current = NULL;

    if (n <= 1)
        return head;

    struct song **songArray = (struct song **)malloc(n * sizeof(struct song *));
    if (songArray == NULL)
    {
        printf("Memory Allocation Failed! Shuffling Fail\n");
        return head;
    }
    current = head;
    for (int i = 0; i < n; i++)
    {
        songArray[i] = current;
        current = current->next;
    }
    // seed of current time to get random numbers
    srand((unsigned int)time(NULL));

    for (int i = (n - 1); i > 0; i--)
    {
        int j = rand() % (i + 1);
        struct song *swapTemporary;
        // swap the terms with randomly generated index elements
        swapTemporary = songArray[i];
        songArray[i] = songArray[j];
        songArray[j] = swapTemporary;
    }

    head = songArray[0];
    for (int i = 0; i < n - 1; i++)
    {
        songArray[i]->next = songArray[i + 1];
    }
    songArray[n - 1]->next = NULL;
    free(songArray);
    return head;
}

int main()
{
    struct song *head = NULL;
    char songAdd[100], songInsert[100];
    int choice = 0;
    do
    {
        printf("\n\n     ~~Make a playlist~~\n\n");
        printf("Choose any option:\n\n");
        printf("1.Add a song to playlist\n");
        printf("2.Insert a song into playlist\n");
        printf("3.Remove a song from playlist\n");
        printf("4.Shuffle the playlist\n");
        printf("5.Exit.\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int addOpt;
            displayAllSongs();
            printf("\nEnter song of your choice: (1-10)\n");
            scanf("%d", &addOpt);
            if (isSongAvailable(chooseSongs(addOpt)))
            {
                strcpy(songAdd, chooseSongs(addOpt));
                head = addSong(head, songAdd);
                displayPlaylist(head);
            }
            else
                printf("\nSong is not available!\n");
            break;
        }
        case 2:
        {
            int insertOpt;
            int insertPos;
            displayAllSongs();
            printf("\nEnter song of your choice: (1-10)\n");
            scanf("%d", &insertOpt);
            printf("Enter position for inserting:\n");
            scanf("%d", &insertPos);
            if (isSongAvailable(chooseSongs(insertOpt)))
            {
                strcpy(songInsert, chooseSongs(insertOpt));
                head = insertSong(head, songInsert, insertPos);
                displayPlaylist(head);
            }
            else
                printf("\nSong is not available!\n");

            break;
        }
        case 3:
        {
            int removePos;
            displayPlaylist(head);
            printf("Enter position for removing:\n");
            scanf("%d", &removePos);
            head = removeSong(head, removePos);
            displayPlaylist(head);
            break;
        }
        case 4:
        {
            displayPlaylist(head);
            head = shufflePlaylist(head);
            printf("\nShuffled Playlist:\n");
            displayPlaylist(head);
            break;
        }
        case 5:
        {
            printf("Exiting System...Bye!!\n\n");
            break;
        }
        default:
        {
            printf("Invalid Input!!\n");
        }
        }
    } while (choice != 5);
    return 0;
}