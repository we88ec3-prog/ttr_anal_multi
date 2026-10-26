
char * FUN_00732a50(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void **ppvVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f383;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ppvVar1 = &local_10;
  local_10 = ExceptionList;
  for (piVar6 = param_1; ExceptionList = ppvVar1, piVar6 != (int *)0x0; piVar6 = (int *)piVar6[4]) {
    iVar4 = (**(code **)(*piVar6 + 0x10))(uVar3);
    if (iVar4 != 0) {
      local_14 = (**(code **)(*piVar6 + 0x10))();
      goto LAB_00732a9c;
    }
    ppvVar1 = ExceptionList;
  }
  local_14 = 0;
LAB_00732a9c:
  pcVar5 = (char *)FUN_00731170(param_4);
  do {
    if (pcVar5 == (char *)0x0) {
      if (local_14 != 0) {
        FUN_00732010(6,0,0,param_4);
      }
      ExceptionList = local_10;
      return (char *)0x0;
    }
    if (*pcVar5 == '\0') {
      ExceptionList = local_10;
      return pcVar5;
    }
    if (*pcVar5 == '<') {
      pcVar7 = "</";
      do {
        if (*pcVar7 == '\0') {
          ExceptionList = local_10;
          return pcVar5;
        }
      } while (((pcVar5 + -0xc44d10)[(int)pcVar7] == *pcVar7) &&
              (pcVar7 = pcVar7 + 1, (pcVar5 + -0xc44d10)[(int)pcVar7] != '\0'));
      if (*pcVar7 == '\0') {
        ExceptionList = local_10;
        return pcVar5;
      }
      piVar6 = (int *)FUN_007320a0(param_1,pcVar5,param_4);
      if (piVar6 == (int *)0x0) {
        ExceptionList = local_10;
        return (char *)0x0;
      }
      (**(code **)(*piVar6 + 8))(pcVar5,param_3,param_4);
LAB_00732bc4:
      FUN_0072e0d0();
    }
    else {
      piVar6 = (int *)FUN_00891268(0x48);
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6[2] = -1;
        piVar6[1] = -1;
        piVar6[3] = 0;
        piVar6[0xd] = 0xf;
        piVar6[0xc] = 0;
        *(undefined1 *)(piVar6 + 8) = 0;
        piVar6[4] = 0;
        piVar6[5] = 4;
        piVar6[6] = 0;
        piVar6[7] = 0;
        piVar6[0xf] = 0;
        piVar6[0x10] = 0;
        local_8 = 1;
        *piVar6 = (int)TiXmlText::vftable;
        FUN_00402a70(&DAT_00bf2375,0);
        *(undefined1 *)(piVar6 + 0x11) = 0;
      }
      local_8 = 0xffffffff;
      if (piVar6 == (int *)0x0) {
        if (local_14 != 0) {
          FUN_00732010(3,0,0,param_4);
        }
        ExceptionList = local_10;
        return (char *)0x0;
      }
      (**(code **)(*piVar6 + 8))(pcVar5,param_3,param_4);
      cVar2 = FUN_00733920(piVar6);
      if (cVar2 == '\0') goto LAB_00732bc4;
      (**(code **)*piVar6)(1);
    }
    pcVar5 = (char *)FUN_00731170(param_4);
  } while( true );
}

