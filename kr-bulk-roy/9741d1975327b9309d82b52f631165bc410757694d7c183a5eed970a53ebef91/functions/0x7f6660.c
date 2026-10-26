
void FUN_007f6660(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int in_ECX;
  int *piVar7;
  char *pcStack_38;
  undefined **appuStack_34 [3];
  undefined1 auStack_28 [4];
  int *piStack_24;
  undefined4 uStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093737c;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x20) != 0) {
    iVar2 = *(int *)(in_ECX + 0x3c);
    if (iVar2 != 0) {
      FUN_007fd2a0(iVar2);
      FUN_0089120c(iVar2);
      *(undefined4 *)(in_ECX + 0x3c) = 0;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(uVar6);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
    }
    uVar4 = DAT_00fb76a8;
    uStack_20 = 0;
    piStack_24 = (int *)FUN_00891268(0x2c);
    if (piStack_24 == (int *)0x0) {
      pcStack_38 = (char *)0x0;
      std::exception::exception((exception *)appuStack_34,&pcStack_38);
      appuStack_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(appuStack_34,&DAT_00c857a8);
    }
    *piStack_24 = (int)piStack_24;
    piStack_24[1] = (int)piStack_24;
    piStack_24[2] = (int)piStack_24;
    *(undefined1 *)(piStack_24 + 10) = 1;
    *(undefined1 *)((int)piStack_24 + 0x29) = 1;
    local_c = 2;
    FUN_007c6ce0(uVar4,*(undefined4 *)(in_ECX + 0x30),auStack_28);
    piVar7 = (int *)*piStack_24;
    if (piVar7 != piStack_24) {
      do {
        if ((DAT_00fe1ac0 & 1) == 0) {
          DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
          local_c._0_1_ = 3;
          FUN_007bb970();
          _atexit((_func_4879 *)&LAB_00bceac0);
          local_c = CONCAT31(local_c._1_3_,2);
        }
        FUN_007bcf60();
        if (*(char *)((int)piVar7 + 0x29) == '\0') {
          piVar3 = (int *)piVar7[2];
          if (*(char *)((int)piVar3 + 0x29) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x29);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x29);
              piVar7 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0x29);
            piVar5 = (int *)piVar7[1];
            piVar3 = piVar7;
            while ((piVar7 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
              cVar1 = *(char *)(piVar7[1] + 0x29);
              piVar5 = (int *)piVar7[1];
              piVar3 = piVar7;
            }
          }
        }
      } while (piVar7 != piStack_24);
    }
    if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x34))(1);
      *(undefined4 *)(in_ECX + 0x34) = 0;
    }
    if (*(undefined4 **)(in_ECX + 0x30) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x30))(1);
      *(undefined4 *)(in_ECX + 0x30) = 0;
    }
    *(undefined4 *)(in_ECX + 0x20) = 0;
    local_c = 4;
    FUN_004ad180(*piStack_24,piStack_24);
    FUN_0089120c(piStack_24);
  }
  ExceptionList = local_14;
  return;
}

