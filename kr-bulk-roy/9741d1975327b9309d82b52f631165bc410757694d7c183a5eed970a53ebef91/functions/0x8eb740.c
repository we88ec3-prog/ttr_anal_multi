
int FUN_008eb740(undefined2 param_1,undefined2 param_2)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_EDI;
  
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  *in_EAX = unaff_EDI;
  uVar1 = FUN_008bc7d0();
  in_EAX[3] = uVar1;
  if (in_ECX != 0) {
    FUN_008eb6e0();
    return in_ECX;
  }
  uVar1 = FUN_008bc7d0();
  in_EAX[4] = uVar1;
  uVar1 = FUN_008bc7d0();
  in_EAX[5] = uVar1;
  uVar1 = FUN_008bc7d0();
  in_EAX[6] = uVar1;
  uVar1 = FUN_008bc7d0();
  in_EAX[7] = uVar1;
  *(undefined2 *)((int)in_EAX + 6) = param_2;
  *(undefined2 *)(in_EAX + 1) = param_1;
  return 0;
}

