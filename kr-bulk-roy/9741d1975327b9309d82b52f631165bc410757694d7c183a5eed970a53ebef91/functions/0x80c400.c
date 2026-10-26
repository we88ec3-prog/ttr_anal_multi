
void FUN_0080c400(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  int *unaff_EDI;
  
  uVar3 = 0;
  if (unaff_EDI[1] - *unaff_EDI >> 2 != 0) {
    do {
      *(undefined4 *)(*(int *)(*unaff_EDI + uVar3 * 4) + 0x14) = 1;
      SetEvent(*(HANDLE *)(*(int *)(*unaff_EDI + uVar3 * 4) + 4));
      puVar1 = (undefined4 *)**(undefined4 **)(*unaff_EDI + uVar3 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        if ((HANDLE)*puVar1 != (HANDLE)0xffffffff) {
          WaitForSingleObject((HANDLE)*puVar1,0xffffffff);
          CloseHandle((HANDLE)*puVar1);
          *puVar1 = 0xffffffff;
          if ((undefined4 *)puVar1[2] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)puVar1[2])(1);
          }
          puVar1[2] = 0;
        }
        FUN_0089120c(puVar1);
      }
      CloseHandle(*(HANDLE *)(*(int *)(*unaff_EDI + uVar3 * 4) + 4));
      iVar2 = *(int *)(*unaff_EDI + uVar3 * 4);
      if (iVar2 != 0) {
        if (0xf < *(uint *)(iVar2 + 0x30)) {
          FUN_0089120c(*(undefined4 *)(iVar2 + 0x1c));
        }
        *(undefined4 *)(iVar2 + 0x30) = 0xf;
        *(undefined4 *)(iVar2 + 0x2c) = 0;
        *(undefined1 *)(iVar2 + 0x1c) = 0;
        FUN_0089120c(iVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(unaff_EDI[1] - *unaff_EDI >> 2));
  }
  _Dst = (void *)*unaff_EDI;
  if (_Dst != (void *)unaff_EDI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_EDI[1],0);
    unaff_EDI[1] = (int)_Dst;
  }
  return;
}

