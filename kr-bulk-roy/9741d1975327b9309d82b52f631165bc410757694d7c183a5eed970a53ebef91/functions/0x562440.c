
void FUN_00562440(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_8 [4];
  
  piVar1 = (int *)FUN_00713cc0(&DAT_00bed1e0);
  if (piVar1 != (int *)0x0) {
    FUN_00851420();
    do {
      iVar2 = (**(code **)(*piVar1 + 0x10))(local_8,4,1);
      uVar3 = FUN_006bde40(local_8);
      FUN_00436890(&DAT_00fb7434,uVar3);
    } while (iVar2 == 1);
    (**(code **)(*piVar1 + 4))();
  }
  return;
}

