
/* WARNING: Removing unreachable block (ram,0x008d15b1) */
/* WARNING: Removing unreachable block (ram,0x008d15c3) */
/* WARNING: Removing unreachable block (ram,0x008d15bd) */
/* WARNING: Removing unreachable block (ram,0x008d15c9) */
/* WARNING: Removing unreachable block (ram,0x008d1672) */
/* WARNING: Removing unreachable block (ram,0x008d167f) */
/* WARNING: Removing unreachable block (ram,0x008d16ea) */
/* WARNING: Removing unreachable block (ram,0x008d16fa) */
/* WARNING: Removing unreachable block (ram,0x008d16f4) */

int FUN_008d1540(undefined4 *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  bool bVar5;
  int local_14;
  
  pbVar3 = (byte *)*param_1;
  local_14 = 1;
  bVar5 = false;
  if (param_2 <= pbVar3) {
    return 0;
  }
  bVar1 = *pbVar3;
  if ((bVar1 == 0x2d) || (bVar1 == 0x2b)) {
    bVar5 = bVar1 == 0x2d;
    pbVar3 = pbVar3 + 1;
    if (pbVar3 == param_2) {
      return 0;
    }
  }
  if (*pbVar3 == 0x2e) {
    iVar2 = 0;
    if ((pbVar3 < param_2) && (*pbVar3 == 0x2e)) {
      while ((((pbVar3 = pbVar3 + 1, pbVar3 < param_2 &&
               ((((bVar1 = *pbVar3, bVar1 != 0x20 && (bVar1 != 0xd)) && (bVar1 != 10)) &&
                ((bVar1 != 9 && (bVar1 != 0xc)))))) && (bVar1 != 0)) &&
             ((bVar1 < 0x80 && ((byte)(&DAT_00be7e60)[bVar1 & 0x7f] < 10))))) {
        if (iVar2 < 0xccccccc) {
          iVar2 = (int)(char)(&DAT_00be7e60)[bVar1 & 0x7f] + iVar2 * 10;
          if (param_3 < 1) {
            local_14 = local_14 * 10;
          }
          else {
            param_3 = param_3 + -1;
          }
        }
      }
    }
    if ((pbVar3 + 1 < param_2) && ((*pbVar3 == 0x65 || (*pbVar3 == 0x45)))) {
      FUN_008d14e0();
    }
    else {
      *param_1 = pbVar3;
      if (iVar2 != 0) {
        do {
          if (param_3 < 1) {
            iVar4 = 0;
            for (; param_3 < 0; param_3 = param_3 + 1) {
              iVar4 = iVar4 / 10;
              if (local_14 < 0xccccccc) {
                local_14 = local_14 * 10;
              }
              else {
                iVar2 = iVar2 / 10;
              }
              if ((iVar4 == 0) && (iVar2 == 0)) {
                return 0;
              }
            }
            if (iVar2 != 0) {
              iVar2 = FUN_008b7f40(iVar2,local_14);
              iVar4 = iVar4 + iVar2;
            }
LAB_008d177f:
            if (bVar5) {
              iVar4 = -iVar4;
            }
            return iVar4;
          }
          if (iVar2 < 0xccccccc) {
            iVar2 = iVar2 * 10;
          }
          else {
            if (local_14 == 1) {
              iVar4 = 0x7fffffff;
              goto LAB_008d177f;
            }
            local_14 = local_14 / 10;
          }
          param_3 = param_3 + -1;
        } while( true );
      }
    }
  }
  else {
    FUN_008d14e0();
  }
  return 0;
}

