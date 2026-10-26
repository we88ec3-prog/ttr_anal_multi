
undefined4 FUN_004dc730(int param_1,int param_2)

{
  void *_Src;
  void *_Dst;
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int unaff_EDI;
  int local_8;
  
  FUN_004dd400(unaff_EDI,&local_8,&param_1);
  if (local_8 == *(int *)(unaff_EDI + 4)) {
    return 0;
  }
  if (*(char *)(*(int *)(local_8 + 0x18) + 0x15) != '\0') {
    piVar3 = *(int **)(unaff_EDI + 0x10);
    uVar1 = *(int *)(unaff_EDI + 0x14) - (int)piVar3 >> 2;
    uVar2 = 0;
    if (uVar1 != 0) {
      do {
        if ((*(int *)*piVar3 == param_1) && (((int *)*piVar3)[1] == param_2)) {
          _Dst = (void *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);
          _Src = (void *)((int)_Dst + 4);
          FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_EDI + 0x14) - (int)_Src >> 2) * 4);
          *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x14) + -4;
          break;
        }
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar2 < uVar1);
    }
  }
  if (*(int *)(local_8 + 0x18) != 0) {
    FUN_004dc7f0();
    *(undefined4 *)(local_8 + 0x18) = 0;
  }
  FUN_006d71c0(unaff_EDI,&param_2,local_8);
  return 1;
}

