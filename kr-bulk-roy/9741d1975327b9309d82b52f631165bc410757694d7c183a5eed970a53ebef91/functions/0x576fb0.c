
void FUN_00576fb0(void)

{
  int iVar1;
  int in_ECX;
  float local_c;
  float local_8;
  
  if (*(int *)(in_ECX + 0x70) != 0) {
    iVar1 = *(int *)(in_ECX + 4);
    if (*(int *)(iVar1 + 4) != 0) {
      local_c = (float)(int)*(float *)(in_ECX + 0xfc);
      local_8 = (float)(int)*(float *)(in_ECX + 0x100);
      (**(code **)(**(int **)(iVar1 + 4) + 0x34))(&local_c,0,*(undefined4 *)(iVar1 + 0x10));
    }
    if (*(int *)(in_ECX + 0x88) != 0) {
      iVar1 = FUN_006dfc40();
      if (*(int *)(iVar1 + 0x18) < *(int *)(in_ECX + 0xd8) + *(int *)(in_ECX + 0xe0)) {
        *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) - *(int *)(in_ECX + 0xe0);
      }
      if (*(int *)(*(int *)(in_ECX + 4) + 0xc) != 0) {
        local_c = (float)*(int *)(in_ECX + 0xd8);
        local_8 = (float)*(int *)(in_ECX + 0xdc);
        (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x34))(&local_c,0,0xffffffff);
      }
    }
  }
  return;
}

