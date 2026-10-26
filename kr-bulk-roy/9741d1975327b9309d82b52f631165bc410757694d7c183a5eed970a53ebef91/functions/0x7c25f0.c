
void FUN_007c25f0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  int *piVar8;
  char *local_3c [2];
  undefined **local_34 [3];
  undefined1 local_28 [4];
  int *local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00937d8c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  piVar2 = *(int **)(in_ECX + 4);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  uVar4 = DAT_00fb76a8;
  local_c = 0xffffffff;
  piVar6 = (int *)**(undefined4 **)(in_ECX + 4);
  do {
    do {
      while( true ) {
        do {
          piVar8 = piVar6;
          if (piVar8 == piVar2) {
            ExceptionList = local_14;
            return;
          }
          iVar3 = piVar8[10];
          local_20 = 0;
          piVar6 = (int *)FUN_00891268(0x2c);
          if (piVar6 == (int *)0x0) {
            local_3c[0] = (char *)0x0;
            std::exception::exception((exception *)local_34,local_3c);
            local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_34,&DAT_00c857a8);
          }
          *piVar6 = (int)piVar6;
          piVar6[1] = (int)piVar6;
          piVar6[2] = (int)piVar6;
          *(undefined1 *)(piVar6 + 10) = 1;
          *(undefined1 *)((int)piVar6 + 0x29) = 1;
          local_c = 2;
          local_24 = piVar6;
          FUN_007c6ce0(uVar4,*(undefined4 *)(iVar3 + 0x1c),local_28);
          piVar6 = (int *)*local_24;
          if (piVar6 != local_24) {
            do {
              if ((DAT_00fe1ac0 & 1) == 0) {
                DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
                local_c._0_1_ = 3;
                FUN_007bb970();
                _atexit((_func_4879 *)&LAB_00bceac0);
                local_c = CONCAT31(local_c._1_3_,2);
              }
              FUN_007bcf60();
              if (*(char *)((int)piVar6 + 0x29) == '\0') {
                piVar7 = (int *)piVar6[2];
                if (*(char *)((int)piVar7 + 0x29) == '\0') {
                  cVar1 = *(char *)(*piVar7 + 0x29);
                  piVar6 = piVar7;
                  piVar7 = (int *)*piVar7;
                  while (cVar1 == '\0') {
                    cVar1 = *(char *)(*piVar7 + 0x29);
                    piVar6 = piVar7;
                    piVar7 = (int *)*piVar7;
                  }
                }
                else {
                  cVar1 = *(char *)(piVar6[1] + 0x29);
                  piVar5 = (int *)piVar6[1];
                  piVar7 = piVar6;
                  while ((piVar6 = piVar5, cVar1 == '\0' && (piVar7 == (int *)piVar6[2]))) {
                    cVar1 = *(char *)(piVar6[1] + 0x29);
                    piVar5 = (int *)piVar6[1];
                    piVar7 = piVar6;
                  }
                }
              }
            } while (piVar6 != local_24);
          }
          if (*(undefined4 **)(iVar3 + 0x1c) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(iVar3 + 0x1c))(1);
            *(undefined4 *)(iVar3 + 0x1c) = 0;
          }
          local_c = 4;
          FUN_004ad180(*local_24,local_24);
          local_c = 0xffffffff;
          FUN_0089120c(local_24);
          piVar6 = piVar8;
        } while (*(char *)((int)piVar8 + 0x2d) != '\0');
        piVar6 = (int *)piVar8[2];
        if (*(char *)((int)piVar6 + 0x2d) != '\0') break;
        cVar1 = *(char *)(*piVar6 + 0x2d);
        piVar8 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar8 + 0x2d);
          piVar6 = piVar8;
          piVar8 = (int *)*piVar8;
        }
      }
      piVar6 = (int *)piVar8[1];
    } while (*(char *)((int)piVar6 + 0x2d) != '\0');
    do {
      piVar7 = piVar6;
      piVar6 = piVar7;
      if (piVar8 != (int *)piVar7[2]) break;
      piVar6 = (int *)piVar7[1];
      piVar8 = piVar7;
    } while (*(char *)((int)piVar6 + 0x2d) == '\0');
  } while( true );
}

