
void FUN_008e3480(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int unaff_EBX;
  int iVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_008e1ab0(*(undefined4 *)(unaff_EBX + 0x2dc8),*(undefined4 *)(unaff_EBX + 0x2dcc),&local_8,
               &local_10);
  FUN_008e1ab0(param_3,param_4,&local_18,&local_20);
  iVar5 = *(int *)(unaff_EBX + 4);
  iVar3 = FUN_008e0e60(param_4);
  piVar1 = (int *)(iVar5 + 0x10);
  *piVar1 = *piVar1 + iVar3;
  iVar3 = *(int *)(unaff_EBX + 0x2dcc) + local_10;
  local_10 = local_10 + param_2;
  iVar5 = *(int *)(unaff_EBX + 0x2dc8) + local_8;
  local_14 = local_8 + param_1;
  local_1c = local_18 + param_3;
  iVar4 = local_18 + param_5;
  local_18 = param_4 + local_20;
  local_20 = local_20 + param_6;
  local_c = iVar5;
  local_8 = iVar3;
  if (*(char *)(unaff_EBX + 0x2d93) != '\0') {
    FUN_008e1a00(iVar5,iVar3);
    *(undefined1 *)(unaff_EBX + 0x2d93) = 0;
    *(undefined1 *)(unaff_EBX + 0x2d90) = 1;
    *(int *)(unaff_EBX + 0x2dc0) = local_14;
    *(int *)(unaff_EBX + 0x2dc4) = local_10;
  }
  if (*(char *)(unaff_EBX + 0x2de0) != '\0') {
    FUN_008e17e0(unaff_EBX + 8,local_14,local_10,0);
    iVar5 = local_c;
    iVar3 = local_8;
  }
  *(int *)(unaff_EBX + 0x2df4) = local_10;
  *(int *)(unaff_EBX + 0x2df0) = local_14;
  *(int *)(unaff_EBX + 0x2e00) = iVar4;
  *(int *)(unaff_EBX + 0x2df8) = local_1c;
  *(int *)(unaff_EBX + 0x2dfc) = local_18;
  *(undefined1 *)(unaff_EBX + 0x2de0) = 1;
  *(undefined4 *)(unaff_EBX + 0x2de4) = 4;
  *(int *)(unaff_EBX + 0x2de8) = iVar5;
  *(int *)(unaff_EBX + 0x2dec) = iVar3;
  *(int *)(unaff_EBX + 0x2e04) = local_20;
  cVar2 = FUN_008e1cf0();
  if (cVar2 != '\0') {
    FUN_008e2ff0(unaff_EBX + 8,*(undefined4 *)(unaff_EBX + 0x2d94),
                 *(undefined4 *)(unaff_EBX + 0x2d98),extraout_ECX,
                 *(undefined4 *)(unaff_EBX + 0x2da0),0);
    *(int *)(unaff_EBX + 0x2dc8) = param_5;
    *(int *)(unaff_EBX + 0x2dcc) = param_6;
    return;
  }
  *(int *)(unaff_EBX + 0x2dc8) = param_5;
  *(int *)(unaff_EBX + 0x2dcc) = param_6;
  return;
}

