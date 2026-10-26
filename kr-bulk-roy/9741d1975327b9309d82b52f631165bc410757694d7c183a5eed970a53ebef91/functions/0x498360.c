
void FUN_00498360(uint param_1,int *param_2,uint param_3,uint param_4)

{
  uint in_EAX;
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *unaff_ESI;
  int iVar6;
  int iVar7;
  
  uVar3 = unaff_ESI[4];
  if ((uVar3 < in_EAX) || ((uint)param_2[4] < param_3)) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar1 = uVar3 - in_EAX;
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  uVar5 = param_2[4] - param_3;
  if (uVar5 < param_4) {
    param_4 = uVar5;
  }
  if (-param_4 - 1 <= uVar3 - param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  uVar1 = uVar1 - param_1;
  uVar5 = (uVar3 - param_1) + param_4;
  if (uVar3 < uVar5) {
    if (0x7ffffffe < uVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)unaff_ESI[5] < uVar5) {
      FUN_00402490(uVar5,uVar3);
    }
    else if (uVar5 == 0) {
      unaff_ESI[4] = 0;
      piVar2 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        piVar2 = (int *)*unaff_ESI;
      }
      *(undefined2 *)piVar2 = 0;
    }
  }
  if (unaff_ESI == param_2) {
    if (param_1 < param_4) {
      if (in_EAX < param_3) {
        uVar3 = param_1 + in_EAX;
        if (param_3 < uVar3) {
          piVar4 = unaff_ESI;
          piVar2 = unaff_ESI;
          if (7 < (uint)unaff_ESI[5]) {
            piVar4 = (int *)*unaff_ESI;
            piVar2 = (int *)*unaff_ESI;
          }
          FUN_004027e0((int)piVar4 + in_EAX * 2,(int)piVar2 + param_3 * 2,param_1);
          piVar4 = unaff_ESI;
          piVar2 = unaff_ESI;
          if (7 < (uint)unaff_ESI[5]) {
            piVar4 = (int *)*unaff_ESI;
            piVar2 = (int *)*unaff_ESI;
          }
          FUN_004027e0((int)piVar4 + (in_EAX + param_4) * 2,(int)piVar2 + uVar3 * 2,uVar1);
          piVar4 = unaff_ESI;
          piVar2 = unaff_ESI;
          if (7 < (uint)unaff_ESI[5]) {
            piVar4 = (int *)*unaff_ESI;
            piVar2 = (int *)*unaff_ESI;
          }
          uVar1 = param_4 - param_1;
          iVar7 = (int)piVar2 + (param_3 + param_4) * 2;
          iVar6 = (int)piVar4 + uVar3 * 2;
        }
        else {
          piVar4 = unaff_ESI;
          piVar2 = unaff_ESI;
          if (7 < (uint)unaff_ESI[5]) {
            piVar4 = (int *)*unaff_ESI;
            piVar2 = (int *)*unaff_ESI;
          }
          FUN_004027e0((int)piVar4 + (in_EAX + param_4) * 2,(int)piVar2 + uVar3 * 2,uVar1);
          piVar4 = unaff_ESI;
          piVar2 = unaff_ESI;
          if (7 < (uint)unaff_ESI[5]) {
            piVar4 = (int *)*unaff_ESI;
            piVar2 = (int *)*unaff_ESI;
          }
          iVar7 = (int)piVar2 + ((param_3 - param_1) + param_4) * 2;
          iVar6 = (int)piVar4 + in_EAX * 2;
          uVar1 = param_4;
        }
      }
      else {
        piVar4 = unaff_ESI;
        piVar2 = unaff_ESI;
        if (7 < (uint)unaff_ESI[5]) {
          piVar4 = (int *)*unaff_ESI;
          piVar2 = (int *)*unaff_ESI;
        }
        FUN_004027e0((int)piVar4 + (in_EAX + param_4) * 2,(int)piVar2 + (param_1 + in_EAX) * 2,uVar1
                    );
        if ((uint)unaff_ESI[5] < 8) {
          iVar7 = (int)unaff_ESI + param_3 * 2;
          iVar6 = (int)unaff_ESI + in_EAX * 2;
          uVar1 = param_4;
        }
        else {
          iVar7 = *unaff_ESI + param_3 * 2;
          iVar6 = *unaff_ESI + in_EAX * 2;
          uVar1 = param_4;
        }
      }
    }
    else {
      piVar4 = unaff_ESI;
      piVar2 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        piVar4 = (int *)*unaff_ESI;
        piVar2 = (int *)*unaff_ESI;
      }
      FUN_004027e0((int)piVar4 + in_EAX * 2,(int)piVar2 + param_3 * 2,param_4);
      piVar4 = unaff_ESI;
      piVar2 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        piVar4 = (int *)*unaff_ESI;
        piVar2 = (int *)*unaff_ESI;
      }
      iVar7 = (int)piVar2 + (param_1 + in_EAX) * 2;
      iVar6 = (int)piVar4 + (in_EAX + param_4) * 2;
    }
    FUN_004027e0(iVar6,iVar7,uVar1);
  }
  else {
    piVar4 = unaff_ESI;
    piVar2 = unaff_ESI;
    if (7 < (uint)unaff_ESI[5]) {
      piVar4 = (int *)*unaff_ESI;
      piVar2 = (int *)*unaff_ESI;
    }
    FID_conflict__memcpy
              ((void *)((int)piVar4 + (in_EAX + param_4) * 2),
               (void *)((int)piVar2 + (param_1 + in_EAX) * 2),uVar1 * 2);
    if (7 < (uint)param_2[5]) {
      param_2 = (int *)*param_2;
    }
    piVar2 = unaff_ESI;
    if (7 < (uint)unaff_ESI[5]) {
      piVar2 = (int *)*unaff_ESI;
    }
    FID_conflict__memcpy
              ((void *)((int)piVar2 + in_EAX * 2),(void *)((int)param_2 + param_3 * 2),param_4 * 2);
  }
  unaff_ESI[4] = uVar5;
  if (7 < (uint)unaff_ESI[5]) {
    *(undefined2 *)(*unaff_ESI + uVar5 * 2) = 0;
    return;
  }
  *(undefined2 *)((int)unaff_ESI + uVar5 * 2) = 0;
  return;
}

