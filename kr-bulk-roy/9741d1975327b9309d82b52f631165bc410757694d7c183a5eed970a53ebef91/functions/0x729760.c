
undefined4 FUN_00729760(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_8;
  
  local_8 = 1;
  if (in_EAX != 0) {
    *(undefined4 *)(in_EAX + 0x18) = 0;
    if (*(int *)(in_EAX + 0x20) == 0) {
      *(code **)(in_EAX + 0x20) = FUN_0072b9c0;
      *(undefined4 *)(in_EAX + 0x28) = 0;
    }
    if (*(int *)(in_EAX + 0x24) == 0) {
      *(code **)(in_EAX + 0x24) = FUN_0072b9e0;
    }
    if (param_1 == 0xffffffff) {
      param_1 = 6;
    }
    if (param_2 < 0) {
      local_8 = 0;
      param_2 = -param_2;
    }
    else if (0xf < param_2) {
      local_8 = 2;
      param_2 = param_2 + -0x10;
    }
    if (((param_2 - 8U < 8) && (param_1 < 10)) && (param_3 < 5)) {
      if (param_2 == 8) {
        param_2 = 9;
      }
      piVar2 = (int *)(**(code **)(in_EAX + 0x20))(*(undefined4 *)(in_EAX + 0x28),1,0x16c0);
      if (piVar2 != (int *)0x0) {
        *(int **)(in_EAX + 0x1c) = piVar2;
        piVar2[6] = local_8;
        iVar3 = 1 << ((byte)param_2 & 0x1f);
        *piVar2 = in_EAX;
        piVar2[7] = 0;
        piVar2[0xc] = param_2;
        piVar2[0xb] = iVar3;
        piVar2[0xd] = iVar3 + -1;
        piVar2[0x14] = 0xf;
        piVar2[0x13] = 0x8000;
        piVar2[0x15] = 0x7fff;
        piVar2[0x16] = 5;
        iVar3 = (**(code **)(in_EAX + 0x20))(*(undefined4 *)(in_EAX + 0x28),iVar3,2);
        piVar2[0xe] = iVar3;
        iVar3 = (**(code **)(in_EAX + 0x20))(*(undefined4 *)(in_EAX + 0x28),piVar2[0xb],2);
        piVar2[0x10] = iVar3;
        iVar3 = (**(code **)(in_EAX + 0x20))(*(undefined4 *)(in_EAX + 0x28),piVar2[0x13],2);
        piVar2[0x11] = iVar3;
        piVar2[0x5a7] = 0x4000;
        iVar3 = (**(code **)(in_EAX + 0x20))(*(undefined4 *)(in_EAX + 0x28),0x4000,4);
        uVar1 = piVar2[0x5a7];
        piVar2[2] = iVar3;
        piVar2[3] = uVar1 * 4;
        if (((piVar2[0xe] != 0) && (piVar2[0x10] != 0)) && ((piVar2[0x11] != 0 && (iVar3 != 0)))) {
          piVar2[0x5a9] = iVar3 + (uVar1 & 0xfffffffe);
          piVar2[0x5a6] = iVar3 + uVar1 * 3;
          piVar2[0x21] = param_1;
          piVar2[0x22] = param_3;
          *(undefined1 *)(piVar2 + 9) = 8;
          uVar4 = FUN_00729920();
          return uVar4;
        }
        piVar2[1] = 0x29a;
        *(char **)(in_EAX + 0x18) = "insufficient memory";
        FUN_0072a1e0();
      }
      return 0xfffffffc;
    }
  }
  return 0xfffffffe;
}

