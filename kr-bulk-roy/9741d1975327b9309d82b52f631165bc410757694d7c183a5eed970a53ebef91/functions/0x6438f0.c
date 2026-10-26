
void FUN_006438f0(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *_Dst;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_8;
  
  *(undefined4 *)(param_1 + 0xdc) = 0;
  FUN_00746780(param_1);
  puVar8 = *(undefined4 **)(param_1 + 0xa8);
  puVar2 = *(undefined4 **)(param_1 + 0xac);
  if (puVar8 != puVar2) {
    puVar1 = (uint *)(param_1 + 0xb8);
    do {
      puVar3 = *(undefined4 **)(param_1 + 0xbc);
      uVar4 = *puVar8;
      local_8 = uVar4;
      if ((&local_8 < puVar3) && (puVar5 = (undefined4 *)*puVar1, puVar5 <= &local_8)) {
        if (puVar3 == *(undefined4 **)(param_1 + 0xc0)) {
          uVar6 = (int)puVar3 - (int)puVar5 >> 2;
          if (0x3ffffffe < uVar6) {
LAB_00643a4e:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar6 = uVar6 + 1;
          uVar7 = (int)*(undefined4 **)(param_1 + 0xc0) - (int)puVar5 >> 2;
          if (uVar7 < uVar6) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_00797980(uVar7);
          }
        }
        if (*(undefined4 **)(param_1 + 0xbc) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0xbc) =
               *(undefined4 *)(*puVar1 + ((int)&local_8 - (int)puVar5 >> 2) * 4);
        }
      }
      else {
        if (puVar3 == *(undefined4 **)(param_1 + 0xc0)) {
          uVar6 = (int)((int)puVar3 - *puVar1) >> 2;
          if (0x3ffffffe < uVar6) goto LAB_00643a4e;
          uVar6 = uVar6 + 1;
          uVar7 = (int)((int)*(undefined4 **)(param_1 + 0xc0) - *puVar1) >> 2;
          if (uVar7 < uVar6) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_00797980(uVar7);
          }
        }
        if (*(undefined4 **)(param_1 + 0xbc) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0xbc) = uVar4;
        }
      }
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 4;
      puVar8 = puVar8 + 1;
    } while (puVar8 != puVar2);
  }
  _Dst = *(void **)(param_1 + 0xa8);
  if (_Dst != *(void **)(param_1 + 0xac)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0xac),0);
    *(void **)(param_1 + 0xac) = _Dst;
  }
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return;
}

