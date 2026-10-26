
uint FUN_00718300(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_8;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    uVar1 = FID_conflict__wprintf("File is not opened!\n");
    return uVar1 & 0xffffff00;
  }
  uStack_8 = in_ECX;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))((int)&uStack_8 + 3,1,1);
  if ((iVar2 != 1) && (*(int **)(in_ECX + 8) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  }
  return (uint)(*(byte *)(in_ECX + 0x20c) ^ uStack_8._3_1_);
}

