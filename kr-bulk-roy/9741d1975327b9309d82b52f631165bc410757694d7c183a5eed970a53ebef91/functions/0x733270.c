
void FUN_00733270(char *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int *in_ECX;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009195a8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_00402a70(&DAT_00bf2375,0);
  for (piVar1 = in_ECX; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {
    iVar3 = (**(code **)(*piVar1 + 0x10))(uVar2);
    if (iVar3 != 0) {
      (**(code **)(*piVar1 + 0x10))();
      break;
    }
  }
  if (param_2 != (int *)0x0) {
    FUN_00730f80(param_1,param_3);
    in_ECX[1] = *param_2;
    in_ECX[2] = param_2[1];
  }
  if ((char)in_ECX[0x11] == '\0') {
    pcVar4 = "<![CDATA[";
    if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
      do {
        if (*pcVar4 == '\0') goto LAB_0073335c;
      } while (((param_1 + -0xc44d14)[(int)pcVar4] == *pcVar4) &&
              (pcVar4 = pcVar4 + 1, (param_1 + -0xc44d14)[(int)pcVar4] != '\0'));
      if (*pcVar4 == '\0') goto LAB_0073335c;
    }
    FUN_007315f0(in_ECX + 8,1,&DAT_00c44d0c);
  }
  else {
LAB_0073335c:
    *(undefined1 *)(in_ECX + 0x11) = 1;
    pcVar4 = "<![CDATA[";
    if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
      do {
        if (*pcVar4 == '\0') goto LAB_007333a0;
      } while (((param_1 + -0xc44d14)[(int)pcVar4] == *pcVar4) &&
              (pcVar4 = pcVar4 + 1, (param_1 + -0xc44d14)[(int)pcVar4] != '\0'));
      if (*pcVar4 == '\0') {
LAB_007333a0:
        pcVar4 = param_1 + 9;
        if (pcVar4 != (char *)0x0) {
          param_1 = param_1 + -0xc44d17;
          while (*pcVar4 != '\0') {
            pcVar5 = "]]>";
            do {
              if (*pcVar5 == '\0') goto LAB_007333ec;
            } while ((param_1[(int)pcVar5] == *pcVar5) &&
                    (pcVar5 = pcVar5 + 1, param_1[(int)pcVar5] != '\0'));
            if (*pcVar5 == '\0') break;
            FUN_00429630(1,*pcVar4);
            param_1 = param_1 + 1;
            pcVar4 = pcVar4 + 1;
            if (pcVar4 == (char *)0x0) break;
          }
        }
LAB_007333ec:
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        local_8 = 0;
        FUN_007315f0(local_30,0,&DAT_00c44d20);
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        goto LAB_0073342b;
      }
    }
    FUN_00732010(0xf,param_1,param_2,param_3);
  }
LAB_0073342b:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

