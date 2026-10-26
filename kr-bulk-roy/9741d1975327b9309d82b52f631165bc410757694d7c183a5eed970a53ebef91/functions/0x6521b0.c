
void FUN_006521b0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  uint in_ECX;
  short *psVar4;
  int iVar5;
  int *piVar6;
  uint local_4c;
  undefined4 uStack_48;
  uint uStack_34;
  int local_2c [6];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d5b6;
  local_14 = ExceptionList;
  local_2c[4] = DAT_00d61f20 ^ (uint)&local_4c;
  ExceptionList = &local_14;
  local_4c = in_ECX;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0065222c;
    in_ECX = FUN_00745c20();
  }
  if ((((in_ECX != 0) && (*(int *)(in_ECX + 0x60) != 0)) &&
      ((*(uint *)(in_ECX + 0x28) >> 0xc & 1) == 0)) && (*(int *)(in_ECX + 0x60) != 0)) {
    FUN_0074a010(in_ECX);
  }
LAB_0065222c:
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_2c[2] = 0;
  local_2c[3] = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar5 = 1;
  piVar6 = (int *)(DAT_00f94300 + 0x1724);
  do {
    if (iVar5 - 1U < 100) {
      if (((*piVar6 != 0) && (piVar6[-1] != 0)) && (piVar6 != (int *)0xc)) {
        iVar2 = 0;
        do {
          if (*piVar6 == (&DAT_00f86060)[iVar2]) {
            local_2c[iVar2] = local_2c[iVar2] + piVar6[-1];
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 4);
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 8;
    if (100 < iVar5) {
      piVar6 = (int *)(local_4c + 0xf8);
      iVar5 = 0;
      do {
        if (*(int *)((int)local_2c + iVar5) == 0) {
          (**(code **)(*(int *)*piVar6 + 0x1ac))
                    (0xffffffff,*(undefined4 *)((int)&DAT_00f86060 + iVar5),0,0,0xffffffff);
          (**(code **)(*(int *)*piVar6 + 0x90))(0);
          (**(code **)(*(int *)*piVar6 + 200))();
        }
        else {
          (**(code **)(*(int *)*piVar6 + 0x1ac))
                    (0xffffffff,*(undefined4 *)((int)&DAT_00f86060 + iVar5),0,0,
                     *(int *)((int)local_2c + iVar5));
          (**(code **)(*(int *)*piVar6 + 0x90))(1);
          (**(code **)(*(int *)*piVar6 + 200))();
        }
        local_4c = 7;
        local_2c[2] = 1;
        iVar2 = *(int *)(*piVar6 + 0x25c);
        if (iVar2 != 0) {
          if (*(uint *)(iVar2 + 0xac) < 8) {
            psVar4 = (short *)(iVar2 + 0x98);
          }
          else {
            psVar4 = *(short **)(iVar2 + 0x98);
          }
          psVar3 = psVar4;
          do {
            sVar1 = *psVar3;
            psVar3 = psVar3 + 1;
          } while (sVar1 != 0);
          FUN_00402160(psVar4,(int)psVar3 - (int)(psVar4 + 1) >> 1);
        }
        FUN_00757710();
        (**(code **)(*(int *)piVar6[4] + 200))();
        local_c = 0xffffffff;
        if (7 < uStack_34) {
          FUN_0089120c(uStack_48);
        }
        iVar5 = iVar5 + 4;
        piVar6 = piVar6 + 1;
      } while (iVar5 < 0x10);
      ExceptionList = local_14;
      __security_check_cookie(local_2c[4] ^ (uint)&local_4c);
      return;
    }
  } while( true );
}

