
void FUN_007243b0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *in_EAX;
  int *piVar2;
  int *piVar3;
  undefined4 *unaff_ESI;
  int iVar4;
  undefined1 local_24 [4];
  int *local_20;
  int *local_1c;
  int local_14;
  int local_10 [3];
  
  iVar1 = param_1;
  iVar4 = *(int *)(param_1 + 4);
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  *unaff_ESI = 1;
  if (iVar4 == 0) {
    piVar3 = in_EAX;
    if (in_EAX[1] != 0) {
      param_1 = 0;
      piVar3 = &param_1;
    }
    if (*piVar3 != 0) {
      if (in_EAX[1] != 0) {
        param_1 = 0;
        in_EAX = &param_1;
      }
      param_1 = *in_EAX;
      FUN_00726680(iVar1);
    }
    FUN_0071d5a0(unaff_ESI,0,param_2);
  }
  else {
    FUN_0071efc0(local_24,in_EAX,param_2);
    piVar3 = local_20;
    if (local_20 != local_1c) {
      do {
        iVar4 = (int)(unaff_ESI[2] - unaff_ESI[1]) >> 3;
        if (iVar4 != 0) {
          *unaff_ESI = 0;
        }
        piVar2 = piVar3;
        if (piVar3[1] != 0) {
          local_10[1] = 0;
          piVar2 = local_10 + 1;
        }
        if (*piVar2 != 0) {
          piVar2 = piVar3;
          if (piVar3[1] != 0) {
            local_10[0] = 0;
            piVar2 = local_10;
          }
          local_14 = *piVar2;
          FUN_00726680(param_1);
        }
        FUN_0071d5a0(unaff_ESI,iVar4,param_2);
        piVar3 = piVar3 + 2;
      } while (piVar3 != local_1c);
      return;
    }
  }
  return;
}

