
uint FUN_004f6d20(int *param_1,wchar_t *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  wchar_t *_Str1;
  int *piVar5;
  int *piVar6;
  int unaff_EDI;
  
  piVar5 = *(int **)(unaff_EDI + 0x104);
  piVar6 = (int *)*piVar5;
  if (piVar6 != piVar5) {
    do {
      _Str1 = (wchar_t *)piVar6[4];
      if (7 < *(uint *)(_Str1 + 10)) {
        _Str1 = *(wchar_t **)_Str1;
      }
      piVar5 = (int *)_wcsncmp(_Str1,param_2,0x14);
      if (piVar5 == (int *)0x0) {
        iVar3 = piVar6[3];
        *param_1 = iVar3;
        return CONCAT31((int3)((uint)iVar3 >> 8),1);
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar5 = (int *)*piVar2;
          while (piVar6 = piVar2, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x15);
            piVar2 = piVar5;
            piVar5 = (int *)*piVar5;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar5 = piVar4, piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar5[2])))
          {
            cVar1 = *(char *)(piVar5[1] + 0x15);
            piVar4 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar6 != *(int **)(unaff_EDI + 0x104));
  }
  return (uint)piVar5 & 0xffffff00;
}

