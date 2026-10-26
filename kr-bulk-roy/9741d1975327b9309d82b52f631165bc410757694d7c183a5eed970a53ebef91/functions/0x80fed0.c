
void FUN_0080fed0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    alSourceStop(*(undefined4 *)(in_ECX + 0x10));
    FUN_00810080();
    FUN_0080ffb0(in_ECX);
    alDeleteSources(1,(undefined4 *)(in_ECX + 0x10));
    FUN_00810080();
    alDeleteBuffers(2,in_ECX + 8);
    FUN_00810080();
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x20024) = 0;
    *(undefined4 *)(in_ECX + 0x20028) = 0;
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}

