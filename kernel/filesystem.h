#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdint.h>

#define SZYMFS_MAGIC 0x535A594D  // "SZYM" in hex
#define MAX_FILES 32
#define MAX_FILENAME 32
#define MAX_FILE_SIZE 4096
#define SECTOR_SIZE 512
#define FS_START_SECTOR 2048

typedef struct {
    char name[MAX_FILENAME];
    uint32_t size;
    uint32_t offset;
    uint8_t used;
} file_entry_t;

typedef struct {
    uint32_t magic;
    uint32_t file_count;
    file_entry_t files[MAX_FILES];
} filesystem_header_t;

// Filesystem functions
void fs_init(void);
int fs_create_file(const char* name, const char* content);
int fs_read_file(const char* name, char* buffer, uint32_t max_size);
int fs_delete_file(const char* name);
void fs_list_files(void);
int fs_file_exists(const char* name);
void fs_save_to_disk(void);
void fs_load_from_disk(void);
void fs_set_drive_info(uint16_t io_base, uint8_t drive_num);

#endif