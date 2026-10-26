
void FUN_007f1c80(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  undefined1 auStack_5c [4];
  int *local_58;
  undefined1 local_54 [4];
  int *local_50;
  undefined4 local_4c;
  undefined **local_44 [3];
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00937666;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  local_4c = 0;
  local_50 = (int *)FUN_00891268(0x2c,DAT_00d61f20 ^ (uint)&stack0xffffff98);
  if (local_50 != (int *)0x0) {
    *local_50 = (int)local_50;
    local_50[1] = (int)local_50;
    local_50[2] = (int)local_50;
    *(undefined1 *)(local_50 + 10) = 1;
    *(undefined1 *)((int)local_50 + 0x29) = 1;
    local_c._1_3_ = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c._0_1_ = 0;
    FUN_007c6ce0(DAT_00fb76a8,*(undefined4 *)(in_ECX + 0x88),local_54);
    local_24 = 0xf;
    local_28 = 0;
    local_38 = local_38 & 0xffffff00;
    local_c._0_1_ = 2;
    piVar4 = (int *)*local_50;
    local_58 = local_50;
    if (piVar4 != local_50) {
      do {
        FUN_00402a70("Effect/Texture/",0xf);
        FUN_00401ed0(piVar4 + 3,0,0xffffffff);
        if ((DAT_00fe1ac0 & 1) == 0) {
          DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
          local_c._0_1_ = 3;
          FUN_007bb970();
          _atexit((_func_4879 *)&LAB_00bceac0);
          local_c._0_1_ = 2;
        }
        FUN_007bcf60();
        if (*(char *)((int)piVar4 + 0x29) == '\0') {
          piVar2 = (int *)piVar4[2];
          if (*(char *)((int)piVar2 + 0x29) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x29);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x29);
              piVar4 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar4[1] + 0x29);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
            while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
              cVar1 = *(char *)(piVar4[1] + 0x29);
              piVar3 = (int *)piVar4[1];
              piVar2 = piVar4;
            }
          }
        }
      } while (piVar4 != local_58);
      if (0xf < local_24) {
        FUN_0089120c(local_38);
      }
    }
    local_24 = 0xf;
    local_28 = 0;
    local_38 = local_38 & 0xffffff00;
    local_c = 4;
    FUN_004ad180(*local_50,local_50);
    FUN_0089120c(local_50);
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)auStack_5c);
    return;
  }
  local_58 = (int *)0x0;
  std::exception::exception((exception *)local_44,(char **)&local_58);
  local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_44,&DAT_00c857a8);
}

