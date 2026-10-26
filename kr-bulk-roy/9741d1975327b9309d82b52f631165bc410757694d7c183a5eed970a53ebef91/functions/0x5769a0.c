
void FUN_005769a0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char ****ppppcVar4;
  char ****ppppcVar5;
  int *piVar6;
  int in_ECX;
  char ***pppcStack_f0;
  char ***pppcStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  uint auStack_e0 [4];
  float *pfStack_d0;
  undefined1 *puStack_cc;
  undefined1 auStack_b4 [3];
  char cStack_b1;
  int iStack_b0;
  int iStack_ac;
  undefined1 *puStack_a8;
  float fStack_a4;
  float fStack_a0;
  uint uStack_9c;
  undefined4 uStack_8c;
  uint uStack_88;
  char ***apppcStack_80 [5];
  uint uStack_6c;
  undefined1 auStack_64 [24];
  int iStack_4c;
  float fStack_44;
  float fStack_40;
  int iStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fa3f;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_b4;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    puStack_cc = (undefined1 *)0x576a0c;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  switch(DAT_00f9392c) {
  case 3:
  case 5:
  case 7:
  case 8:
  case 0x15:
  case 0x17:
  case 0x18:
  case 0x1b:
    break;
  default:
    *(undefined4 *)(in_ECX + 0x70) = 0;
  }
  if (*(int *)(in_ECX + 0x70) != 0) {
    puStack_cc = (undefined1 *)0xffffffff;
    pfStack_d0 = (float *)0x576a57;
    iVar3 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 4) + 0x38))();
    if (iVar3 != 0) {
      iVar3 = *(int *)(*(int *)(in_ECX + 8) + 0x24);
      iStack_ac = iVar3;
      FUN_005750a0();
      local_c = 1;
      iStack_b0 = 0;
      if (0 < iVar3) {
        do {
          puStack_cc = *(undefined1 **)(in_ECX + 8);
          pfStack_d0 = (float *)0x576a99;
          FUN_00572cd0();
          if (iStack_4c == 6) {
            puStack_a8 = (undefined1 *)auStack_e0;
            uStack_e4 = 0xffffffff;
            uStack_e8 = 0;
            pppcStack_ec = (char ***)apppcStack_80;
            puStack_cc = (undefined1 *)0xf;
            pfStack_d0 = (float *)0x0;
            auStack_e0[0] = auStack_e0[0] & 0xffffff00;
            pppcStack_f0 = (char ***)0x576bc8;
            FUN_00403040();
            uStack_e4 = 0x576bcd;
            iVar3 = FUN_0057e490();
            if (*(int *)(*(int *)(in_ECX + 4) + 8) != 0) {
              fStack_a4 = (float)(int)fStack_44;
              fStack_a0 = (float)(int)fStack_40;
              puStack_cc = (undefined1 *)(in_ECX + 0x20 + iVar3 * 0x1c);
              pfStack_d0 = &fStack_a4;
              auStack_e0[3] = 0x576c21;
              (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x34))();
            }
          }
          else if (iStack_4c == 7) {
            if (iStack_3c != 0) {
              pfStack_d0 = (float *)(int)fStack_40;
              auStack_e0[3] = (uint)fStack_44;
              puStack_cc = auStack_64;
              puStack_a8 = (undefined1 *)&pppcStack_f0;
              ppppcVar4 = (char ****)apppcStack_80[0];
              if (uStack_6c < 0x10) {
                ppppcVar4 = apppcStack_80;
              }
              auStack_e0[1] = 0xf;
              auStack_e0[0] = 0;
              pppcStack_f0 = (char ***)((uint)pppcStack_f0 & 0xffffff00);
              ppppcVar5 = ppppcVar4;
              do {
                cVar2 = *(char *)ppppcVar5;
                ppppcVar5 = (char ****)((int)ppppcVar5 + 1);
              } while (cVar2 != '\0');
              FUN_0040b310(ppppcVar4);
              FUN_005755f0();
            }
          }
          else if (iStack_3c != 0) {
            puStack_cc = (undefined1 *)(int)fStack_40;
            pfStack_d0 = (float *)(int)fStack_44;
            puStack_a8 = (undefined1 *)&pppcStack_ec;
            pppcStack_f0 = apppcStack_80[0];
            if (uStack_6c < 0x10) {
              pppcStack_f0 = (char ***)apppcStack_80;
            }
            auStack_e0[2] = 0xf;
            auStack_e0[1] = 0;
            pppcStack_ec = (char ***)((uint)pppcStack_ec & 0xffffff00);
            ppppcVar4 = (char ****)pppcStack_f0;
            do {
              cVar2 = *(char *)ppppcVar4;
              ppppcVar4 = (char ****)((int)ppppcVar4 + 1);
            } while (cVar2 != '\0');
            FUN_0040b310();
            pppcStack_f0 = (char ***)0x576b21;
            FUN_00575500();
          }
          iStack_b0 = iStack_b0 + 1;
        } while (iStack_b0 < iStack_ac);
      }
      (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 4) + 0x3c))();
      local_c = 0xffffffff;
      if (0xf < uStack_6c) {
        puStack_cc = (undefined1 *)0x576c5d;
        FUN_0089120c();
      }
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    uStack_9c = uStack_9c & 0xffffff00;
    puStack_cc = (undefined1 *)0x576c88;
    FUN_0040b310();
    local_c = 2;
    piVar1 = *(int **)(in_ECX + 8);
    iVar3 = *piVar1;
    puStack_cc = (undefined1 *)0x576ca4;
    iStack_ac = FUN_006cf160();
    if ((iStack_ac == *(int *)(iVar3 + 4)) || (cVar2 = FUN_005436a0(), cVar2 != '\0')) {
      iStack_b0 = *(int *)(iVar3 + 4);
      piVar6 = &iStack_b0;
    }
    else {
      piVar6 = &iStack_ac;
    }
    if (*piVar6 == *(int *)(*piVar1 + 4)) {
      iVar3 = 2;
    }
    else {
      iVar3 = *(int *)(*(int *)(*piVar6 + 0x28) + 0x1c);
    }
    cStack_b1 = iVar3 == 4;
    local_c = 0xffffffff;
    if (0xf < uStack_88) {
      puStack_cc = (undefined1 *)0x576d08;
      FUN_0089120c();
    }
    if (cStack_b1 != '\0') {
      uStack_88 = 0xf;
      uStack_8c = 0;
      uStack_9c = uStack_9c & 0xffffff00;
      puStack_cc = (undefined1 *)0x576d3e;
      FUN_0040b310();
      local_c = 3;
      piVar1 = *(int **)(in_ECX + 8);
      iVar3 = *piVar1;
      puStack_cc = (undefined1 *)0x576d5a;
      iStack_ac = FUN_006cf160();
      if ((iStack_ac == *(int *)(iVar3 + 4)) || (cVar2 = FUN_005436a0(), cVar2 != '\0')) {
        iStack_b0 = *(int *)(iVar3 + 4);
        piVar6 = &iStack_b0;
      }
      else {
        piVar6 = &iStack_ac;
      }
      if (*piVar6 != *(int *)(*piVar1 + 4)) {
        *(undefined4 *)(*(int *)(*piVar6 + 0x28) + 0x1c) = 3;
      }
      local_c = 0xffffffff;
      if (0xf < uStack_88) {
        puStack_cc = (undefined1 *)0x576db3;
        FUN_0089120c();
      }
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    uStack_9c = uStack_9c & 0xffffff00;
    puStack_cc = (undefined1 *)0x576dde;
    FUN_0040b310();
    local_c = 4;
    piVar1 = *(int **)(in_ECX + 8);
    iVar3 = *piVar1;
    puStack_cc = (undefined1 *)0x576dfa;
    iStack_ac = FUN_006cf160();
    if ((iStack_ac == *(int *)(iVar3 + 4)) || (cVar2 = FUN_005436a0(), cVar2 != '\0')) {
      iStack_b0 = *(int *)(iVar3 + 4);
      piVar6 = &iStack_b0;
    }
    else {
      piVar6 = &iStack_ac;
    }
    if (*piVar6 == *(int *)(*piVar1 + 4)) {
      iVar3 = 2;
    }
    else {
      iVar3 = *(int *)(*(int *)(*piVar6 + 0x28) + 0x1c);
    }
    cStack_b1 = iVar3 == 4;
    local_c = 0xffffffff;
    if (0xf < uStack_88) {
      puStack_cc = (undefined1 *)0x576e62;
      FUN_0089120c();
    }
    if (cStack_b1 != '\0') {
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      puStack_cc = (undefined1 *)0x576ea4;
      FUN_0040b310();
      local_c = 5;
      piVar1 = *(int **)(in_ECX + 8);
      iVar3 = *piVar1;
      puStack_cc = (undefined1 *)0x576ec3;
      iStack_ac = FUN_006cf160();
      if ((iStack_ac == *(int *)(iVar3 + 4)) || (cVar2 = FUN_005436a0(), cVar2 != '\0')) {
        iStack_b0 = *(int *)(iVar3 + 4);
        piVar6 = &iStack_b0;
      }
      else {
        piVar6 = &iStack_ac;
      }
      if (*piVar6 != *(int *)(*piVar1 + 4)) {
        *(undefined4 *)(*(int *)(*piVar6 + 0x28) + 0x1c) = 3;
      }
      if (0xf < uStack_24) {
        puStack_cc = (undefined1 *)0x576f19;
        FUN_0089120c();
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_b4);
  return;
}

