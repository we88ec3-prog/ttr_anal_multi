
undefined4 * FUN_004860b0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_EDI;
  bool bVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f658;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar6 = true;
  cVar1 = *(char *)((int)puVar2 + 0x21);
  puVar5 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar6 = *(int *)(param_2 + 0xc) < (int)puVar2[3];
    if (bVar6) {
      puVar4 = (undefined4 *)*puVar2;
    }
    else {
      puVar4 = (undefined4 *)puVar2[2];
    }
    puVar5 = puVar2;
    puVar2 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x21);
  }
  if (bVar6) {
    if (puVar5 != (undefined4 *)**(int **)(param_1 + 4)) {
      FUN_008377c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      goto LAB_0048613f;
    }
    bVar6 = true;
  }
  else {
LAB_0048613f:
    iVar3 = param_2;
    if (*(int *)(param_2 + 0xc) <= (int)puVar5[3]) {
      local_8 = 0;
      FUN_004ca160(**(undefined4 **)(param_2 + 0x14),*(undefined4 **)(param_2 + 0x14));
      FUN_0089120c(*(undefined4 *)(iVar3 + 0x14));
      FUN_0089120c(param_2);
      *(undefined1 *)(unaff_EDI + 1) = 0;
      goto LAB_0048618c;
    }
  }
  puVar5 = (undefined4 *)FUN_004862b0(&param_2,bVar6,puVar5,param_2);
  puVar5 = (undefined4 *)*puVar5;
  *(undefined1 *)(unaff_EDI + 1) = 1;
LAB_0048618c:
  *unaff_EDI = puVar5;
  ExceptionList = local_10;
  return unaff_EDI;
}

