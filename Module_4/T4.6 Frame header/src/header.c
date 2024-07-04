#include "header.h"

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */



int validateHeader(uint32_t header) {
    
    uint8_t sync = header & 0x3F; 
    uint8_t ack = (header >> 6) & 0x1; 
    uint8_t v = (header >> 7) & 0x1; 
    uint8_t type = (header >> 8) & 0x7; 
    uint8_t source_address = (header >> 16) & 0xFF; 
    uint8_t dest_address = (header >> 24) & 0xFF; 

    
    if (sync != 0x2a) {
        return 0;
    }

    
    if (ack && !v) {
        return 0;
    }

    
    if (!ack && type == 0) {
        return 0;
    }

    
    if (source_address == 0 || dest_address == 0 || source_address == dest_address) {
        return 0;
    }

    return 1;
}

int getFrameId(uint32_t header) {
    if (!validateHeader(header)) {
        return -1;
    }
    return (header >> 11) & 0x1F;
}

int getFrameType(uint32_t header) {
    if (!validateHeader(header)) {
        return -1;
    }
    if ((header >> 6) & 0x1) { 
        return 0;
    }
    return (header >> 8) & 0x7;
}

int getSourceAddress(uint32_t header) {
    if (!validateHeader(header)) {
        return -1;
    }
    return (header >> 16) & 0xFF;
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid) {
    uint32_t header = 0;
    header |= 0x2a; 
    header |= (1 << 6); 
    if (valid) {
        header |= (1 << 7); 
    }
    header |= ((frameId & 0x1F) << 11); 
    header |= ((sourceAddress & 0xFF) << 16); 
    header |= ((destAddress & 0xFF) << 24); 
    return header;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type) {
    uint32_t header = 0;
    header |= 0x2a; 
    header |= ((type & 0x7) << 8); 
    header |= ((frameId & 0x1F) << 11); 
    header |= ((sourceAddress & 0xFF) << 16); 
    header |= ((destAddress & 0xFF) << 24); 
    return header;
}