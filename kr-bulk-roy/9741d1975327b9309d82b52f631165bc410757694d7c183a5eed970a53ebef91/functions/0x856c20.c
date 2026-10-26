
void FUN_00856c20(undefined4 *****param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 ******ppppppuVar3;
  int in_ECX;
  char *unaff_ESI;
  int iStack_58;
  int iStack_54;
  undefined4 *****pppppuStack_50;
  uint uStack_4c;
  undefined1 auStack_40 [4];
  undefined4 ****appppuStack_3c [2];
  uint uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091e788;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_40;
  uStack_4c = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  pppppuStack_50 = param_1;
  iStack_54 = 0x856c61;
  FUN_007802f0();
  iStack_58 = in_ECX + 0x54;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  iStack_58 = in_ECX + 0x58;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  iStack_58 = in_ECX + 0x5c;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  iStack_58 = in_ECX + 0x60;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  iStack_58 = in_ECX + 100;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  iStack_58 = in_ECX + 0x68;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  iStack_58 = in_ECX + 0x6c;
  if (iStack_58 != 0) {
    pppppuStack_50 = (undefined4 *****)0x0;
    iStack_54 = 4;
    FUN_00721910(param_1[0x22]);
  }
  pppppuStack_50 = appppuStack_3c;
  iStack_54 = in_ECX + 0xb8;
  iStack_58 = 0x856d22;
  (*(code *)(*param_1[0x24])[0x16])();
  pvStack_2c = (void *)0xf;
  uStack_30 = 0;
  auStack_40[0] = 0;
  pcVar2 = unaff_ESI;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_58 = (int)pcVar2 - (int)(unaff_ESI + 1);
  FUN_00402a70(unaff_ESI);
  iStack_58 = 0;
  local_14 = (void *)0x0;
  FUN_00721910(param_1[0x22],&stack0xffffffb8,4);
  ppppppuVar3 = (undefined4 ******)pppppuStack_50;
  if (appppuStack_3c[0] < (undefined4 *****)0x10) {
    ppppppuVar3 = &pppppuStack_50;
  }
  if ((ppppppuVar3 != (undefined4 ******)0x0) && (iStack_58 != 0)) {
    FUN_00721910(param_1[0x22],ppppppuVar3,iStack_58,0);
  }
  if ((undefined4 *****)0xf < appppuStack_3c[0]) {
    FUN_0089120c(pppppuStack_50);
  }
  ExceptionList = pvStack_2c;
  __security_check_cookie(uStack_34 ^ (uint)&iStack_58);
  return;
}

