
void FUN_0070f580(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  undefined4 local_40 [2];
  undefined4 local_38;
  int *local_2c;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar3 = *(int **)(param_1 + 0x30);
  local_2c = piVar3;
  FUN_0070f400();
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar2 - 0x28U < 0xf7) {
    switch(iVar2 - 0x28U) {
    case 0x28:
    case 0x7b:
    case 0x11e:
                    /* WARNING: This code block may not be properly labeled as switch case */
      FUN_007122a0();
      if (((*in_ECX == 0xc) && ((in_ECX[2] & 0x100U) == 0)) &&
         ((int)(uint)*(byte *)((int)piVar3 + 0x32) <= in_ECX[2])) {
        piVar3[9] = piVar3[9] + -1;
      }
      iVar2 = piVar3[9] + 1;
      if ((int)(uint)*(byte *)(*piVar3 + 0x4b) < iVar2) {
        if (0xf9 < iVar2) {
                    /* WARNING: Subroutine does not return */
          FUN_006ff130(piVar3[3],"function or expression too complex",
                       *(undefined4 *)(piVar3[3] + 0x10));
        }
        *(char *)(*piVar3 + 0x4b) = (char)iVar2;
      }
      piVar3[9] = piVar3[9] + 1;
      FUN_00712510();
      FUN_0070f2b0();
      break;
    default:
      goto switchD_0070f5c7_caseD_29;
    case 0x2e:
      FUN_0070e540();
      break;
    case 0x3a:
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
      if (*(int *)(param_1 + 0x20) == 0x11f) {
        uVar1 = FUN_006ffec0(param_1 + 0x18);
        *(undefined4 *)(param_1 + 0x10) = uVar1;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x20) = 0x11f;
      }
      local_40[0] = FUN_0070d950();
      local_18 = 0xffffffff;
      local_14 = 0xffffffff;
      local_38 = 4;
      local_28[0] = 4;
      local_20 = FUN_00712090(*(undefined4 *)(param_1 + 0x30),local_40);
      FUN_00712970(local_28);
      FUN_0070f2b0();
      piVar3 = local_2c;
      break;
    case 0x5b:
      FUN_007122a0();
      if (*in_ECX == 0xc) {
        if (in_ECX[4] != in_ECX[5]) {
          if (in_ECX[2] < (int)(uint)*(byte *)((int)piVar3 + 0x32)) goto LAB_0070f609;
          FUN_00712510();
        }
      }
      else {
LAB_0070f609:
        FUN_00712630();
      }
      FUN_0070e610();
      iVar2 = FUN_00712740();
      in_ECX[3] = iVar2;
      *in_ECX = 9;
      piVar3 = local_2c;
    }
    iVar2 = *(int *)(param_1 + 0x10);
  }
switchD_0070f5c7_caseD_29:
                    /* WARNING: This code block may not be properly labeled as switch case */
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

