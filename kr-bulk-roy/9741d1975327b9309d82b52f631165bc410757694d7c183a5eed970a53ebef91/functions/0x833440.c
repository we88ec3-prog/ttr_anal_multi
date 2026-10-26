
void FUN_00833440(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  
  lVar1 = (ulonglong)(uint)(unaff_EDI[1] * *unaff_EDI) * 4;
  uVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  unaff_ESI[5] = uVar2;
  unaff_ESI[7] = param_1;
  unaff_ESI[6] = unaff_EDI;
  unaff_ESI[8] = param_2;
  unaff_ESI[2] = *unaff_EDI;
  unaff_ESI[3] = unaff_EDI[1];
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  return;
}

