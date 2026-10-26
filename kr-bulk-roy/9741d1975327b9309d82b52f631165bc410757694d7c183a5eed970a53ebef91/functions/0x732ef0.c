
undefined4 FUN_00732ef0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  for (piVar1 = in_ECX; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x10))();
      break;
    }
  }
  FUN_00402a70(&DAT_00bf2375,0);
  pcVar3 = (char *)FUN_00731170(param_3);
  if (param_2 != (int *)0x0) {
    FUN_00730f80(pcVar3,param_3);
    in_ECX[1] = *param_2;
    in_ECX[2] = param_2[1];
  }
  pcVar4 = "<!--";
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    do {
      if (*pcVar4 == '\0') goto LAB_00732fb8;
    } while (((pcVar3 + -0xc44d24)[(int)pcVar4] == *pcVar4) &&
            (pcVar4 = pcVar4 + 1, (pcVar3 + -0xc44d24)[(int)pcVar4] != '\0'));
    if (*pcVar4 == '\0') {
LAB_00732fb8:
      uVar5 = FUN_007315f0(in_ECX + 8,0,&DAT_00c44d2c);
      return uVar5;
    }
  }
  FUN_00732010(0xb,pcVar3,param_2,param_3);
  return 0;
}

