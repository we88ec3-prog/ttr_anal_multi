
/* WARNING: Type propagation algorithm not settling */

int FUN_007fa900(void)

{
  void **ppvVar1;
  void **ppvVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int *in_ECX;
  uint uVar6;
  uint *puVar7;
  int local_1c;
  uint local_18;
  void *local_14 [4];
  
  local_14[3] = (void *)0xffffffff;
  local_14[2] = &LAB_00909b9b;
  local_14[1] = ExceptionList;
  ExceptionList = local_14 + 1;
  uVar3 = (**(code **)(*in_ECX + 0x24))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar4 = FUN_00891268(0xf0);
  local_14[3] = (void *)0x0;
  if (iVar4 == 0) {
    local_1c = 0;
  }
  else {
    if ((uint)in_ECX[0xd] <= uVar3) {
      uVar3 = in_ECX[0xd];
    }
    local_1c = FUN_008016d0(iVar4,in_ECX,uVar3,in_ECX[1]);
  }
  local_14[3] = (void *)0xffffffff;
  *(int *)(local_1c + 0x84) = in_ECX[0xf];
  iVar4 = in_ECX[0x16];
  local_18 = 0;
  if (in_ECX[0x17] - iVar4 >> 2 != 0) {
    puVar7 = (uint *)(local_1c + 0x94);
    do {
      pvVar5 = (void *)(**(code **)(**(int **)(iVar4 + local_18 * 4) + 4))();
      ppvVar1 = *(void ***)(local_1c + 0x98);
      local_14[0] = pvVar5;
      if ((local_14 < ppvVar1) && (ppvVar2 = (void **)*puVar7, ppvVar2 <= local_14)) {
        if (ppvVar1 == *(void ***)(local_1c + 0x9c)) {
          uVar3 = (int)ppvVar1 - (int)ppvVar2 >> 2;
          if (0x3ffffffe < uVar3) {
LAB_007faa9b:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar3 = uVar3 + 1;
          uVar6 = (int)*(void ***)(local_1c + 0x9c) - (int)ppvVar2 >> 2;
          if (uVar6 < uVar3) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar3) {
              uVar6 = uVar3;
            }
            FUN_00797980(uVar6);
          }
        }
        if (*(undefined4 **)(local_1c + 0x98) != (undefined4 *)0x0) {
          **(undefined4 **)(local_1c + 0x98) =
               *(undefined4 *)(*puVar7 + ((int)local_14 - (int)ppvVar2 >> 2) * 4);
        }
      }
      else {
        if (ppvVar1 == *(void ***)(local_1c + 0x9c)) {
          uVar3 = (int)((int)ppvVar1 - *puVar7) >> 2;
          if (0x3ffffffe < uVar3) goto LAB_007faa9b;
          uVar3 = uVar3 + 1;
          uVar6 = (int)((int)*(void ***)(local_1c + 0x9c) - *puVar7) >> 2;
          if (uVar6 < uVar3) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar3) {
              uVar6 = uVar3;
            }
            FUN_00797980(uVar6);
          }
        }
        if (*(undefined4 **)(local_1c + 0x98) != (undefined4 *)0x0) {
          **(undefined4 **)(local_1c + 0x98) = pvVar5;
        }
      }
      *(int *)(local_1c + 0x98) = *(int *)(local_1c + 0x98) + 4;
      iVar4 = in_ECX[0x16];
      local_18 = local_18 + 1;
    } while (local_18 < (uint)(in_ECX[0x17] - iVar4 >> 2));
  }
  ExceptionList = local_14[1];
  return local_1c;
}

