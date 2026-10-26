
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _frexp
   
   Library: Visual Studio 2010 Release */

double __cdecl _frexp(double _X,int *_Y)

{
  double dVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  if (_Y == (int *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    fVar5 = (float10)0;
    goto LAB_00899485;
  }
  uVar3 = __ctrlfp(0x133f,0xffff);
  if ((_X._6_2_ & 0x7ff0) != 0x7ff0) {
    fVar5 = (float10)FUN_008ae5ea(_X,_Y);
    __ctrlfp(uVar3,0xffff);
    fVar5 = (float10)(double)fVar5;
    goto LAB_00899485;
  }
  *_Y = -1;
  iVar4 = __sptype(_X);
  if (iVar4 < 1) {
LAB_00899443:
    dVar1 = _X + 1.0;
  }
  else {
    dVar1 = _DAT_00d62b70;
    if (2 < iVar4) {
      if (iVar4 == 3) {
        fVar5 = (float10)__handle_qnan1();
        goto LAB_00899485;
      }
      goto LAB_00899443;
    }
  }
  fVar5 = (float10)__except1(8,0x17,_X,SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20),uVar3);
LAB_00899485:
  return (double)fVar5;
}

