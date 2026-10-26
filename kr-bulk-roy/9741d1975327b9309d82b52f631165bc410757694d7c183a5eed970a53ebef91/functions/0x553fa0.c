
void FUN_00553fa0(void)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x34) != 0) && (*(int *)(in_ECX + 0x34) != 1)) &&
     (*(int *)(in_ECX + 0x44) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x24))
              (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),0,0,1,0,
               (uint)*(byte *)(in_ECX + 0x38) << 0x18 | 0xffffff);
  }
  return;
}

