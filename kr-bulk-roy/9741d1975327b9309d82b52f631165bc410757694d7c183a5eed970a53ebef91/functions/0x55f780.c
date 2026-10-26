
void FUN_0055f780(int *param_1)

{
  int *piVar1;
  int in_EAX;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *local_10;
  int *local_c;
  int local_8;
  
  if (*param_1 == 0) {
    *param_1 = 1;
  }
  else {
    FUN_0055f5d0();
  }
  local_8 = in_EAX;
  FUN_008438c0(&local_8);
  if ((local_c != (int *)param_1[0x11]) && (local_c = (int *)local_c[4], local_c != (int *)0x0)) {
    param_1[0xe] = in_EAX;
    param_1[10] = 0;
    iVar5 = (local_c[1] - *local_c) / 0x3c;
    if (iVar5 != 0) {
      iVar3 = 0;
      local_8 = iVar5;
      do {
        piVar1 = local_c;
        puVar2 = (undefined2 *)FUN_00891268(0x3c);
        puVar4 = (undefined2 *)0x0;
        if (puVar2 != (undefined2 *)0x0) {
          *(undefined4 *)(puVar2 + 8) = 0;
          *(undefined4 *)(puVar2 + 10) = 7;
          *puVar2 = 0;
          *(undefined4 *)(puVar2 + 0x16) = 0;
          *(undefined4 *)(puVar2 + 0x18) = 0xf;
          *(undefined1 *)(puVar2 + 0xe) = 0;
          puVar4 = puVar2;
        }
        iVar5 = *piVar1 + iVar3;
        local_10 = puVar4;
        FUN_004026e0(iVar5,0,0xffffffff);
        FUN_00403040(iVar5 + 0x1c,0,0xffffffff);
        *(undefined4 *)(puVar4 + 0x1c) = *(undefined4 *)(iVar5 + 0x38);
        FUN_00804260(&local_10);
        iVar3 = iVar3 + 0x3c;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      local_8 = 0;
    }
    FUN_0055f470(param_1);
    param_1[0xb] = 1;
    param_1[0x16] = param_1[0x14];
    param_1[0x1a] = param_1[0x18];
    return;
  }
  FUN_0055f5d0();
  *param_1 = 0;
  return;
}

