
int FUN_0070f1c0(int param_1)

{
  int *piVar1;
  int *in_EAX;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  
  local_c = 1;
  FUN_0070fc00(param_1);
  do {
    if (*(int *)(param_1 + 0x10) != 0x2c) {
      return local_c;
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar2 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar2;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
    piVar1 = *(int **)(param_1 + 0x30);
    FUN_007122a0();
    if (((*in_EAX == 0xc) && ((in_EAX[2] & 0x100U) == 0)) &&
       ((int)(uint)*(byte *)((int)piVar1 + 0x32) <= in_EAX[2])) {
      piVar1[9] = piVar1[9] + -1;
    }
    iVar3 = piVar1[9] + 1;
    if ((int)(uint)*(byte *)(*piVar1 + 0x4b) < iVar3) {
      if (0xf9 < iVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(piVar1[3],"function or expression too complex",
                     *(undefined4 *)(piVar1[3] + 0x10));
      }
      *(char *)(*piVar1 + 0x4b) = (char)iVar3;
    }
    piVar1[9] = piVar1[9] + 1;
    FUN_00712510();
    FUN_0070fc00(param_1);
    local_c = local_c + 1;
  } while( true );
}

