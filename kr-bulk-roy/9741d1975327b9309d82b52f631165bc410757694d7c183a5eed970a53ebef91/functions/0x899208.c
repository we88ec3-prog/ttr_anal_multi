
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _ldexp
   
   Library: Visual Studio 2010 Release */

double __cdecl _ldexp(double _X,int _Y)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  double dVar4;
  undefined4 uVar5;
  int local_8;
  
  uVar1 = __ctrlfp(0x133f,0xffff);
  if ((_X._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar2 = __sptype(_X);
    if (0 < iVar2) {
      if (iVar2 < 3) goto LAB_00899271;
      if (iVar2 == 3) {
        fVar3 = (float10)__handle_qnan2();
        goto LAB_008993b6;
      }
    }
    dVar4 = _X + 1.0;
    uVar5 = 8;
  }
  else {
    if (_X == 0.0) {
LAB_00899271:
      __ctrlfp(uVar1,0xffff);
LAB_008993b3:
      fVar3 = (float10)_X;
      goto LAB_008993b6;
    }
    fVar3 = (float10)FUN_008ae5ea(_X,&local_8);
    if (_Y < 0) {
      if (local_8 < -0x80000000 - _Y) {
LAB_0089935b:
        fVar3 = fVar3 * (float10)0.0;
LAB_00899361:
        dVar4 = (double)fVar3;
        uVar5 = 0x12;
        goto LAB_008992a1;
      }
LAB_008992ef:
      local_8 = _Y + local_8;
      if (0xa00 < local_8) goto LAB_008992f8;
      if (local_8 < 0x401) {
        if (local_8 < -0x9fd) goto LAB_0089935b;
        if (-0x3fe < local_8) {
          fVar3 = (float10)__set_exp((double)fVar3,local_8);
          _X = (double)fVar3;
          __ctrlfp(uVar1,0xffff);
          goto LAB_008993b3;
        }
        fVar3 = (float10)__set_exp((double)fVar3,local_8 + 0x600);
        goto LAB_00899361;
      }
      fVar3 = (float10)__set_exp((double)fVar3,local_8 + -0x600);
      dVar4 = (double)fVar3;
    }
    else {
      if (local_8 <= 0x7fffffff - _Y) goto LAB_008992ef;
LAB_008992f8:
      dVar4 = __copysign(_DAT_00d62b68,(double)fVar3);
    }
    uVar5 = 0x11;
  }
LAB_008992a1:
  fVar3 = (float10)__except2(uVar5,0x19,_X,(double)_Y,dVar4,uVar1);
LAB_008993b6:
  return (double)fVar3;
}

