
undefined4 * FUN_004db900(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  bool bVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar6 = true;
  cVar1 = *(char *)((int)puVar2 + 0x21);
  puVar5 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    bVar6 = *(short *)(param_2 + 0xc) < *(short *)(puVar2 + 3);
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
    if (puVar5 != (undefined4 *)**(int **)(in_ECX + 4)) {
      FUN_008377c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      goto LAB_004db992;
    }
    bVar6 = true;
  }
  else {
LAB_004db992:
    iVar3 = param_2;
    if (*(short *)(param_2 + 0xc) <= *(short *)(puVar5 + 3)) {
      local_8 = 0;
      FUN_0085e680(**(undefined4 **)(param_2 + 0x14),*(undefined4 **)(param_2 + 0x14));
      FUN_0089120c(*(undefined4 *)(iVar3 + 0x14));
      FUN_0089120c(param_2);
      *(undefined1 *)(param_1 + 1) = 0;
      goto LAB_004db9df;
    }
  }
  puVar5 = (undefined4 *)FUN_004dbc40(&param_2,bVar6,puVar5,param_2);
  puVar5 = (undefined4 *)*puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
LAB_004db9df:
  *param_1 = puVar5;
  ExceptionList = local_10;
  return param_1;
}

