
int * FUN_00703f20(int *param_1,uint param_2,char *param_3,uint param_4)

{
  char *_MaxCount;
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_4 == 0) {
    return param_1;
  }
  if (param_2 < param_4) {
    return (int *)0x0;
  }
  _MaxCount = (char *)(param_2 - (param_4 - 1));
  do {
    if ((_MaxCount == (char *)0x0) ||
       (piVar1 = _memchr(param_1,(int)*param_3,(size_t)_MaxCount), piVar1 == (int *)0x0)) {
      return (int *)0x0;
    }
    piVar5 = (int *)((int)piVar1 + 1);
    piVar3 = (int *)(param_3 + 1);
    piVar4 = piVar5;
    for (uVar2 = param_4 - 1; 3 < uVar2; uVar2 = uVar2 - 4) {
      if (*piVar4 != *piVar3) goto LAB_00703fa8;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    if ((uVar2 == 0) ||
       (((char)*piVar3 == (char)*piVar4 &&
        ((uVar2 < 2 ||
         ((*(char *)((int)piVar3 + 1) == *(char *)((int)piVar4 + 1) &&
          ((uVar2 < 3 || (*(char *)((int)piVar3 + 2) == *(char *)((int)piVar4 + 2))))))))))) {
      return piVar1;
    }
LAB_00703fa8:
    _MaxCount = (char *)((int)param_1 + ((int)_MaxCount - (int)piVar5));
    param_1 = piVar5;
  } while( true );
}

