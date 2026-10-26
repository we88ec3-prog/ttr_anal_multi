
void FUN_008e3310(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  cVar1 = FUN_008e1cf0();
  if ((cVar1 == '\0') || (local_5 = '\x01', *(char *)(unaff_ESI + 0x2d91) != '\0')) {
    local_5 = '\0';
  }
  if (((*(int *)(unaff_ESI + 0x2dc8) != param_1) || (*(int *)(unaff_ESI + 0x2dcc) != param_2)) ||
     (local_5 != '\0')) {
    FUN_008e1ab0(*(int *)(unaff_ESI + 0x2dc8),*(undefined4 *)(unaff_ESI + 0x2dcc),&local_c,&local_14
                );
    iVar3 = *(int *)(unaff_ESI + 0x2dc8) + local_c;
    iVar2 = local_c + param_1;
    iVar4 = *(int *)(unaff_ESI + 0x2dcc) + local_14;
    local_14 = local_14 + param_2;
    local_10 = iVar3;
    local_c = iVar4;
    if (*(char *)(unaff_ESI + 0x2d93) != '\0') {
      FUN_008e1a00(iVar3,iVar4);
      *(undefined1 *)(unaff_ESI + 0x2d93) = 0;
      *(undefined1 *)(unaff_ESI + 0x2d90) = 1;
      *(int *)(unaff_ESI + 0x2dc0) = iVar2;
      *(int *)(unaff_ESI + 0x2dc4) = local_14;
    }
    if (*(char *)(unaff_ESI + 0x2de0) != '\0') {
      FUN_008e17e0(unaff_ESI + 8,iVar2,local_14,0);
      iVar3 = local_10;
      iVar4 = local_c;
    }
    *(int *)(unaff_ESI + 0x2dec) = iVar4;
    *(int *)(unaff_ESI + 0x2de8) = iVar3;
    *(undefined1 *)(unaff_ESI + 0x2de0) = 1;
    *(undefined4 *)(unaff_ESI + 0x2de4) = 2;
    *(int *)(unaff_ESI + 0x2df0) = iVar2;
    *(int *)(unaff_ESI + 0x2df4) = local_14;
    if (local_5 != '\0') {
      FUN_008e2ff0(unaff_ESI + 8,*(undefined4 *)(unaff_ESI + 0x2d94),
                   *(undefined4 *)(unaff_ESI + 0x2d98),*(undefined4 *)(unaff_ESI + 0x2d9c),
                   *(undefined4 *)(unaff_ESI + 0x2da0),0);
    }
    *(int *)(unaff_ESI + 0x2dc8) = param_1;
    *(int *)(unaff_ESI + 0x2dcc) = param_2;
  }
  return;
}

