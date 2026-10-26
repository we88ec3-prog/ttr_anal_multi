
int FUN_007320a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cd96;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = (char *)FUN_00731170(param_3,uVar2);
  if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) || (*pcVar3 != '<')) {
    ExceptionList = local_10;
    return 0;
  }
  iVar4 = FUN_0072d980();
  pcVar3 = (char *)FUN_00731170(param_3,uVar2);
  if (pcVar3 == (char *)0x0) {
    ExceptionList = local_10;
    return 0;
  }
  if (*pcVar3 == '\0') {
    ExceptionList = local_10;
    return 0;
  }
  cVar1 = FUN_00731560(1,param_3);
  if (cVar1 == '\0') {
    cVar1 = *pcVar3;
    pcVar6 = "<!--";
    if (cVar1 != '\0') {
      do {
        if (*pcVar6 == '\0') goto LAB_00732177;
      } while (((pcVar3 + -0xc44d24)[(int)pcVar6] == *pcVar6) &&
              (pcVar6 = pcVar6 + 1, (pcVar3 + -0xc44d24)[(int)pcVar6] != '\0'));
      if (*pcVar6 == '\0') {
LAB_00732177:
        iVar5 = FUN_00891268(0x44);
        if (iVar5 != 0) {
          iVar5 = FUN_0072dc60();
          goto LAB_00732277;
        }
        goto LAB_00732147;
      }
    }
    pcVar6 = "<![CDATA[";
    if (cVar1 != '\0') {
      do {
        if (*pcVar6 == '\0') goto LAB_007321b7;
      } while (((pcVar3 + -0xc44d14)[(int)pcVar6] == *pcVar6) &&
              (pcVar6 = pcVar6 + 1, (pcVar3 + -0xc44d14)[(int)pcVar6] != '\0'));
      if (*pcVar6 == '\0') {
LAB_007321b7:
        iVar5 = FUN_00891268(0x48);
        local_8 = 0;
        if (iVar5 == 0) {
          iVar5 = 0;
          local_8 = 0xffffffff;
          uRam00000044 = 1;
        }
        else {
          iVar5 = FUN_0072dcd0(iVar5);
          local_8 = 0xffffffff;
          *(undefined1 *)(iVar5 + 0x44) = 1;
        }
        goto LAB_00732277;
      }
    }
    pcVar6 = "<!";
    if (cVar1 == '\0') {
LAB_00732234:
      iVar5 = FUN_00730f60();
      if ((iVar5 != 0) || (pcVar3[1] == '_')) {
        iVar5 = FUN_00891268(0x98);
        local_8 = 1;
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_0072e420(iVar5,&DAT_00bf2375);
        }
        local_8 = 0xffffffff;
        goto LAB_00732277;
      }
    }
    else {
      do {
        if (*pcVar6 == '\0') goto LAB_0073221b;
      } while (((pcVar3 + -0xc451cc)[(int)pcVar6] == *pcVar6) &&
              (pcVar6 = pcVar6 + 1, (pcVar3 + -0xc451cc)[(int)pcVar6] != '\0'));
      if (*pcVar6 != '\0') goto LAB_00732234;
    }
LAB_0073221b:
    iVar5 = FUN_00891268(0x44);
    if (iVar5 != 0) {
      iVar5 = FUN_0072de00();
      goto LAB_00732277;
    }
  }
  else {
    iVar5 = FUN_00891268(0x98);
    if (iVar5 != 0) {
      iVar5 = FUN_0072dda0();
      goto LAB_00732277;
    }
  }
LAB_00732147:
  iVar5 = 0;
LAB_00732277:
  if (iVar5 == 0) {
    if (iVar4 != 0) {
      FUN_00732010(3,0,0,0);
    }
    ExceptionList = local_10;
    return 0;
  }
  *(undefined4 *)(iVar5 + 0x10) = param_1;
  ExceptionList = local_10;
  return iVar5;
}

