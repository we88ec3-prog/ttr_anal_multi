
int * FUN_00782020(int param_1)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 local_10;
  int local_c;
  
  iVar5 = param_1;
  if (param_1 != 0) {
    if (*(int *)(in_EAX + 0x2c) != 0) {
      FUN_0082ef00(&param_1);
      if (local_c != *(int *)(in_EAX + 0x28)) {
        return *(int **)(local_c + 0x10);
      }
    }
    if (*(int *)(in_EAX + 0x84) != 0) {
      piVar6 = *(int **)(in_EAX + 0x74);
      uVar7 = *(int *)(in_EAX + 0x78) - (int)piVar6 >> 2;
      uVar2 = 0;
      if (uVar7 != 0) {
        if (uVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        do {
          iVar1 = *piVar6;
          if (*(int *)(iVar1 + 4) == iVar5) {
            local_c = FUN_00782420(in_EAX,uVar2);
            local_10 = *(undefined4 *)(iVar1 + 4);
            uVar3 = FUN_007845e0();
            FUN_00784330(&local_10,uVar3);
            puVar4 = (undefined4 *)FUN_00782cb0();
            piVar6 = (int *)*puVar4;
            iVar5 = (**(code **)(*piVar6 + 4))();
            if (*(int *)(iVar5 + 4) == -0x5eed0000) {
              piVar6 = (int *)(**(code **)(*piVar6 + 0xc))();
              return piVar6;
            }
            return piVar6;
          }
          uVar2 = uVar2 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar2 < uVar7);
      }
    }
  }
  return (int *)0x0;
}

