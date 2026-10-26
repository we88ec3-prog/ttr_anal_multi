
/* WARNING: Type propagation algorithm not settling */

void FUN_00629030(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint local_40;
  ushort local_3c;
  int local_38;
  char local_31;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d31c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  if (((uint)in_ECX[10] >> 7 & 1) == 0) {
    in_ECX[0x95] = 0;
    in_ECX[0x94] = 0;
  }
  else {
    local_38 = 0;
    local_40._0_2_ = 0;
    local_31 = '\0';
    uVar4 = 0;
    do {
      if (1 < local_38) break;
      if ((uVar4 != 0x70) && (uVar4 != 0x94)) {
        if (DAT_00fba80c == 0) {
          iVar3 = FUN_00891268(0x57c,uVar2);
          if (iVar3 == 0) {
            DAT_00fba80c = 0;
          }
          else {
            DAT_00fba80c = FUN_006f1370();
          }
        }
        if (((*(int *)(DAT_00fba80c + 0x20) != 0) && ((uVar4 & 0xff) < 0x100)) &&
           (*(char *)((uVar4 & 0xff) + 0x160 + DAT_00fba80c) == '\x01')) {
          if (uVar4 == 0x1c) {
LAB_00629118:
            if (in_ECX[0x95] != in_ECX[0x94]) {
              iVar3 = FUN_00891268(0x24,uVar2);
              if (iVar3 == 0) {
                FUN_00748900();
              }
              else {
                FUN_00753fb0(0xf43cb,in_ECX[0x95],in_ECX[0x94],in_ECX[0x92]);
                FUN_00748900();
              }
            }
            goto LAB_00629505;
          }
          if (uVar4 == 0x9c) {
            if ((char)in_ECX[0x96] != '\0') goto LAB_00629118;
          }
          else if (uVar4 == 1) {
            in_ECX[0x95] = 0;
            FUN_00757710();
            (**(code **)(*in_ECX + 200))();
            if (in_ECX[0x95] != in_ECX[0x94]) {
              iVar3 = FUN_00891268(0x24);
              if (iVar3 != 0) {
                FUN_00753fb0(0xf43cb,in_ECX[0x95],in_ECX[0x94],in_ECX[0x92]);
              }
              FUN_00748900();
              FUN_00629910(in_ECX,in_ECX[0x95]);
            }
            goto LAB_00629505;
          }
          if ((char)in_ECX[0x96] != '\0') {
            local_31 = '\x01';
          }
        }
        iVar3 = FUN_00443dc0();
        if (((((*(int *)(iVar3 + 0x20) != 0) && ((uVar4 & 0xff) < 0x100)) &&
             (*(char *)((uVar4 & 0xff) + 0x160 + iVar3) == '\x01')) ||
            (((iVar3 = FUN_00443dc0(), *(int *)(iVar3 + 0x20) != 0 && ((uVar4 & 0xff) < 0x100)) &&
             (*(char *)((uVar4 & 0xff) + 0x160 + iVar3) == '\x02')))) &&
           ((((((((uVar4 != 0x46 && (uVar4 != 0xc5)) && (uVar4 != 0xb7)) &&
                ((uVar4 != 0x38 && (uVar4 != 0xb8)))) && (uVar4 != 0x3b)) &&
              ((uVar4 != 0x3c && (uVar4 != 0x3d)))) &&
             ((((uVar4 != 0x3e && (((uVar4 != 0x3f && (uVar4 != 0x40)) && (uVar4 != 0x41)))) &&
               ((((uVar4 != 0x42 && (uVar4 != 0x43)) && (uVar4 != 0x44)) &&
                ((uVar4 != 0x57 && (uVar4 != 0x58)))))) &&
              ((uVar4 != 100 && (((uVar4 != 0x65 && (uVar4 != 0x66)) && (uVar4 != 0xdb)))))))) &&
            ((uVar4 != 0xdc && (uVar4 != 0x52)))))) {
          FUN_0049c410();
          *(uint *)((int)&local_40 + local_38 * 2 * 2) = uVar4 & 0xff;
          local_38 = local_38 + 1;
        }
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x100);
    if (local_31 != '\0') {
      if (local_38 == 1) {
        local_1c = 7;
        local_20 = 0;
        local_30 = (uint)local_30._2_2_ << 0x10;
        local_8 = 0;
        if ((DAT_00fdfb10 & 1) == 0) {
          DAT_00fdfb10 = DAT_00fdfb10 | 1;
          local_8._0_1_ = 1;
          local_8._1_3_ = 0;
          FUN_00590760();
          _atexit((_func_4879 *)&LAB_00bce760);
          local_8 = (uint)local_8._1_3_ << 8;
        }
        FUN_004026e0(&DAT_00fdfb1c + (uint)(byte)local_40 * 0x1c,0,0xffffffff);
        in_ECX[0x95] = (uint)(ushort)local_40;
        FUN_00757800(&local_30);
        (**(code **)(*in_ECX + 200))();
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
      }
      else if (local_38 == 2) {
        iVar3 = 0;
        local_1c = 7;
        local_20 = 0;
        local_30 = (uint)local_30._2_2_ << 0x10;
        local_8 = 2;
        bVar1 = false;
        do {
          if ((*(int *)((int)&local_40 + iVar3 * 2 * 2) == 0x1d) ||
             (*(int *)((int)&local_40 + iVar3 * 2 * 2) == 0x9d)) {
            uVar2 = iVar3 + 1U & 0x80000001;
            if ((int)uVar2 < 0) {
              uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
            }
            if ((*(int *)((int)&local_40 + uVar2 * 2 * 2) == 0x1d) ||
               (*(int *)((int)&local_40 + uVar2 * 2 * 2) == 0x9d)) {
              in_ECX[0x95] = 0;
            }
            else {
              in_ECX[0x95] = CONCAT22(*(ushort *)((int)&local_40 + iVar3 * 2 * 2),
                                      *(ushort *)((int)&local_40 + uVar2 * 2 * 2));
              bVar1 = true;
            }
            break;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 2);
        if ((in_ECX[0x95] != 0) && (!bVar1)) {
          in_ECX[0x95] = (uint)local_3c << 0x10;
        }
        if ((DAT_00fdfb10 & 1) == 0) {
          DAT_00fdfb10 = DAT_00fdfb10 | 1;
          local_8._0_1_ = 3;
          local_8._1_3_ = 0;
          FUN_00590760();
          _atexit((_func_4879 *)&LAB_00bce760);
          local_8 = CONCAT31(local_8._1_3_,2);
        }
        FUN_00594570(in_ECX[0x95]);
        FUN_00757800(&local_30);
        (**(code **)(*in_ECX + 200))();
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
        local_1c = 7;
        local_20 = 0;
        local_30 = local_30 & 0xffff0000;
      }
    }
    if ((char)in_ECX[0x96] == '\0') {
      FUN_00629660(in_ECX);
    }
  }
LAB_00629505:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

