
void FUN_004481f0(uint param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint in_EAX;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int *unaff_ESI;
  
  uVar4 = unaff_ESI[4];
  if ((uVar4 < param_1) || ((uint)param_2[4] < param_3)) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar2 = param_2[4] - param_3;
  if (uVar2 < in_EAX) {
    in_EAX = uVar2;
  }
  if (in_EAX < -uVar4 - 1) {
    if (in_EAX != 0) {
      uVar2 = uVar4 + in_EAX;
      if (0x7ffffffe < uVar2) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("string too long");
      }
      if ((uint)unaff_ESI[5] < uVar2) {
        FUN_00402490(uVar2,uVar4);
        if (uVar2 == 0) {
          return;
        }
      }
      else if (uVar2 == 0) {
        unaff_ESI[4] = 0;
        if ((uint)unaff_ESI[5] < 8) {
          *(undefined2 *)unaff_ESI = 0;
          return;
        }
        *(undefined2 *)*unaff_ESI = 0;
        return;
      }
      piVar3 = unaff_ESI;
      piVar1 = unaff_ESI;
      if (7 < (uint)unaff_ESI[5]) {
        piVar3 = (int *)*unaff_ESI;
        piVar1 = (int *)*unaff_ESI;
      }
      FUN_004027e0((int)piVar3 + (param_1 + in_EAX) * 2,(int)piVar1 + param_1 * 2,
                   unaff_ESI[4] - param_1);
      if (unaff_ESI == param_2) {
        uVar4 = param_3 + in_EAX;
        if (param_3 <= param_1) {
          uVar4 = param_3;
        }
        if ((uint)unaff_ESI[5] < 8) {
          FUN_004027e0((int)unaff_ESI + param_1 * 2,(int)unaff_ESI + uVar4 * 2,in_EAX);
        }
        else {
          FUN_004027e0(*unaff_ESI + param_1 * 2,*unaff_ESI + uVar4 * 2,in_EAX);
        }
      }
      else {
        if (7 < (uint)param_2[5]) {
          param_2 = (int *)*param_2;
        }
        if (7 < (uint)unaff_ESI[5]) {
          unaff_ESI = (int *)*unaff_ESI;
        }
        FID_conflict__memcpy
                  ((void *)((int)unaff_ESI + param_1 * 2),(void *)((int)param_2 + param_3 * 2),
                   in_EAX * 2);
      }
      FUN_004029e0(uVar2);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("string too long");
}

