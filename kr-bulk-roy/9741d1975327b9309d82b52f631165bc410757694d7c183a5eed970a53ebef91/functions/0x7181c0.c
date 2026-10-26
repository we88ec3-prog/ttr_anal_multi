
undefined4 FUN_007181c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) == (int *)0x0) {
    FID_conflict__wprintf("File is not opened!\n");
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x34))(0,2);
  uVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x34))(uVar1,0);
  return uVar2;
}

