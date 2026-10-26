
void FUN_008e1420(undefined4 param_1,int param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int *unaff_EBX;
  int *unaff_ESI;
  
  lVar1 = (longlong)unaff_ESI[0xb5f] * (longlong)param_2 +
          (ulonglong)((int)((longlong)unaff_ESI[0xb5f] * (longlong)param_2 >> 0x3f) + 0x8000);
  lVar2 = (longlong)unaff_ESI[0xb60] * (longlong)param_3 +
          (ulonglong)((int)((longlong)unaff_ESI[0xb60] * (longlong)param_3 >> 0x3f) + 0x8000);
  iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 +
          ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
  iVar4 = FUN_008e0f80(param_3);
  lVar1 = (longlong)*(int *)(*unaff_ESI + 0x3c) * (longlong)iVar5;
  lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
  lVar2 = (longlong)*(int *)(*unaff_ESI + 0x44) * (longlong)iVar4;
  lVar3 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
  *unaff_EBX = unaff_ESI[0xb62] + ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000
               + ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
  lVar1 = (longlong)*(int *)(*unaff_ESI + 0x40) * (longlong)iVar5;
  lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
  lVar2 = (longlong)*(int *)(*unaff_ESI + 0x48) * (longlong)iVar4;
  lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
  unaff_EBX[1] = unaff_ESI[0xb63] +
                 ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 +
                 ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
  return;
}

