
int FUN_008c8bd0(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int *unaff_ESI;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 0x68);
  local_8 = (**(code **)(in_EAX + 0x1fc))();
  if (((local_8 != 0) && (local_8 = (**(code **)(in_EAX + 0x1fc))(), local_8 != 0)) &&
     (local_8 = (**(code **)(in_EAX + 0x1fc))(), local_8 != 0)) {
    return local_8;
  }
  *unaff_ESI = in_EAX;
  unaff_ESI[1] = iVar1;
  unaff_ESI[2] = *(int *)(in_EAX + 0x54) + 0x4c;
  unaff_ESI[3] = param_2;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  iVar1 = FUN_008b9850(iVar1);
  unaff_ESI[5] = iVar1;
  unaff_ESI[6] = local_c;
  unaff_ESI[9] = *(int *)(in_EAX + 0x2d4);
  param_1 = param_1 * 0x30;
  unaff_ESI[10] = *(int *)(in_EAX + 0x2d4) + *(int *)(in_EAX + 0x2d8);
  if (param_1 + 0x37U <= *(uint *)(in_EAX + 0x2d8)) {
    iVar1 = param_1 + 0xc + unaff_ESI[9];
    unaff_ESI[7] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 8 + unaff_ESI[9]),
                                              *(undefined1 *)(iVar1 + -3)),
                                     *(undefined1 *)(iVar1 + -2)),*(undefined1 *)(iVar1 + -1));
    unaff_ESI[8] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 4),*(undefined1 *)(iVar1 + 5))
                                     ,*(undefined1 *)(iVar1 + 6)),*(undefined1 *)(iVar1 + 7));
    *(undefined1 *)((int)unaff_ESI + 0x12) = *(undefined1 *)(iVar1 + 0x2a);
    if (((uint)unaff_ESI[7] <= *(uint *)(in_EAX + 0x2d8)) &&
       ((uint)(unaff_ESI[7] + unaff_ESI[8] * 8) <= *(uint *)(in_EAX + 0x2d8))) {
      return local_8;
    }
  }
  return 3;
}

