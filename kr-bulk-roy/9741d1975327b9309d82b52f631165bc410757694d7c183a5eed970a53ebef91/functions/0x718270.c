
uint FUN_00718270(byte *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    FID_conflict__wprintf("File is not opened!\n");
    return 0;
  }
  if (param_2 != 0) {
    uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))(param_1,1,param_2);
    if ((uVar2 < param_2) && (*(int **)(in_ECX + 8) != (int *)0x0)) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
    }
    uVar1 = uVar2;
    if (*(char *)(in_ECX + 0x20c) != '\0') {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *param_1 = *param_1 ^ *(byte *)(in_ECX + 0x20c);
        param_1 = param_1 + 1;
      }
    }
    return uVar2;
  }
  return 0;
}

