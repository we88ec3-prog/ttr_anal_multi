
int * FUN_0079ed00(int *param_1,int *param_2)

{
  char cVar1;
  short *psVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *_Dst;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int in_ECX;
  int iVar8;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938bd8;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = *param_1;
  FUN_00515790(&local_14);
  if (local_18 == *(int *)(in_ECX + 4)) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(*(int *)(local_18 + 0x10) + 0x54);
  }
  piVar7 = (int *)(iVar8 + 0x3c);
  if (0xf < *(uint *)(iVar8 + 0x50)) {
    piVar7 = (int *)*piVar7;
  }
  FID_conflict__wprintf("(%s)DECREF: %d\n",piVar7,*(int *)(iVar8 + 0x5c) + -1,uVar6);
  *(int *)(iVar8 + 0x5c) = *(int *)(iVar8 + 0x5c) + -1;
  if (param_1[4] == 0) {
    FUN_007c5210();
  }
  else {
    piVar7 = *(int **)param_1[3];
    if (piVar7 != (int *)param_1[3]) {
      do {
        FUN_007c5b50(iVar8,0xffffffff);
        local_18 = CONCAT22((short)piVar7[3],*(undefined2 *)((int)piVar7 + 0xe));
        FUN_0082ef00(&local_18);
        if (local_14 != *(int *)(iVar8 + 0xb8)) {
          psVar2 = *(short **)(local_14 + 0x10);
          *psVar2 = *psVar2 + -1;
          if (*psVar2 == 0) {
            FUN_007c4d30(psVar2);
          }
        }
        if (*(char *)((int)piVar7 + 0x11) == '\0') {
          piVar4 = (int *)piVar7[2];
          if (*(char *)((int)piVar4 + 0x11) == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x11);
            piVar7 = piVar4;
            piVar4 = (int *)*piVar4;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar4 + 0x11);
              piVar7 = piVar4;
              piVar4 = (int *)*piVar4;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0x11);
            piVar5 = (int *)piVar7[1];
            piVar4 = piVar7;
            while ((piVar7 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar7[2]))) {
              cVar1 = *(char *)(piVar7[1] + 0x11);
              piVar5 = (int *)piVar7[1];
              piVar4 = piVar7;
            }
          }
        }
      } while (piVar7 != (int *)param_1[3]);
    }
  }
  piVar7 = *(int **)param_1[0xb];
  if (piVar7 != (int *)param_1[0xb]) {
    do {
      puVar3 = (undefined4 *)piVar7[6];
      FUN_007d2990();
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
        piVar4 = (int *)piVar7[2];
        if (*(char *)((int)piVar4 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x21);
          piVar7 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x21);
            piVar7 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x21);
          piVar5 = (int *)piVar7[1];
          piVar4 = piVar7;
          while ((piVar7 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x21);
            piVar5 = (int *)piVar7[1];
            piVar4 = piVar7;
          }
        }
      }
    } while (piVar7 != (int *)param_1[0xb]);
  }
  cVar1 = *(char *)((int)*(int **)(param_1[0xb] + 4) + 0x21);
  piVar7 = *(int **)(param_1[0xb] + 4);
  while (cVar1 == '\0') {
    FUN_008575b0(piVar7[2]);
    piVar4 = (int *)*piVar7;
    FUN_0089120c(piVar7);
    piVar7 = piVar4;
    cVar1 = *(char *)((int)piVar4 + 0x21);
  }
  *(int *)(param_1[0xb] + 4) = param_1[0xb];
  *(int *)param_1[0xb] = param_1[0xb];
  *(int *)(param_1[0xb] + 8) = param_1[0xb];
  param_1[0xc] = 0;
  iVar8 = param_1[1];
  if (iVar8 != 0) {
    piVar7 = *(int **)(iVar8 + 0xa8);
    if (piVar7 != *(int **)(iVar8 + 0xac)) {
      do {
        if ((undefined4 *)*piVar7 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar7)(1);
        }
        piVar7 = piVar7 + 1;
      } while (piVar7 != *(int **)(iVar8 + 0xac));
    }
    _Dst = *(void **)(iVar8 + 0xa8);
    if (_Dst != *(void **)(iVar8 + 0xac)) {
      FID_conflict__memcpy(_Dst,*(void **)(iVar8 + 0xac),0);
      *(void **)(iVar8 + 0xac) = _Dst;
    }
  }
  piVar7 = param_1;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    piVar7 = (int *)(*(code *)**(undefined4 **)param_1[1])(1);
    param_1[1] = 0;
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    piVar4 = param_2 + 1;
    LOCK();
    iVar8 = *piVar4;
    piVar7 = (int *)*piVar4;
    *piVar4 = iVar8 + -1;
    UNLOCK();
    if (iVar8 + -1 == 0) {
      piVar7 = (int *)(**(code **)*param_2)();
      LOCK();
      iVar8 = param_2[2] + -1;
      param_2[2] = iVar8;
      UNLOCK();
      if (iVar8 == 0) {
        piVar7 = (int *)(**(code **)(*param_2 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return piVar7;
}

