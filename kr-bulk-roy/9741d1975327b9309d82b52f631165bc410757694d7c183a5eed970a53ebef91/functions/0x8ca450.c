
int FUN_008ca450(uint param_1,char *param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  void *pvVar10;
  char *pcVar11;
  int iVar12;
  uint _MaxCount;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  int local_c;
  int local_8;
  
  iVar7 = param_1;
  iVar9 = *(int *)(param_1 + 0x58);
  *param_3 = 0;
  if ((*(char *)(param_1 + 0x30c) != '\0') ||
     (local_8 = FUN_008ca290(*(undefined4 *)(param_1 + 0x68)), local_8 == 0)) {
    iVar12 = *(int *)(param_1 + 0x2f8);
    param_1 = *(int *)(param_1 + 0x308);
    local_c = iVar12 + 8 + param_1 * 4;
    local_8 = 6;
    if ((iVar9 != 0) && (param_2 != (char *)0x0)) {
      pcVar11 = param_2;
      do {
        cVar5 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar5 != '\0');
      if ((pcVar11 != param_2 + 1) && (param_1 != 0)) {
        iVar13 = iVar12 + 7;
        iVar12 = iVar12 + 6;
        while( true ) {
          puVar1 = (undefined1 *)(iVar12 + 2);
          puVar2 = (undefined1 *)(iVar13 + 4);
          puVar3 = (undefined1 *)(iVar13 + 2);
          puVar4 = (undefined1 *)(iVar12 + 4);
          iVar12 = iVar12 + 4;
          iVar13 = iVar13 + 4;
          uVar8 = (uint)CONCAT11(*puVar4,*puVar2);
          if (CONCAT11(*puVar1,*puVar3) == *(short *)(iVar9 + 0xe)) break;
          param_1 = param_1 + -1;
          local_c = local_c + uVar8 * 10;
          if (param_1 == 0) {
            return 6;
          }
        }
        if (uVar8 != 0) {
          pbVar15 = (byte *)(local_c + 5);
          param_1 = uVar8;
          do {
            bVar6 = *pbVar15;
            if ((bVar6 & 0x10) != 0) {
              uVar8 = CONCAT31(CONCAT21(CONCAT11(pbVar15[-5],pbVar15[-4]),pbVar15[-3]),pbVar15[-2]);
              uVar14 = CONCAT31(CONCAT21(CONCAT11(pbVar15[1],pbVar15[2]),pbVar15[3]),pbVar15[4]);
              if (((uVar8 < *(uint *)(iVar7 + 0x304)) &&
                  (_MaxCount = *(uint *)(iVar7 + 0x304) - uVar8,
                  (uint)((int)pcVar11 - (int)(param_2 + 1)) < _MaxCount)) &&
                 (iVar9 = _strncmp(param_2,(char *)(*(int *)(iVar7 + 0x300) + uVar8),_MaxCount),
                 iVar9 == 0)) {
                switch(bVar6 & 0xf) {
                case 0:
                case 1:
                  if ((uVar14 < *(uint *)(iVar7 + 0x304)) &&
                     (pvVar10 = _memchr((void *)(*(int *)(iVar7 + 0x300) + uVar14),0,
                                        *(uint *)(iVar7 + 0x304)), pvVar10 != (void *)0x0)) {
                    *param_3 = 1;
                    param_3[1] = *(int *)(iVar7 + 0x300) + uVar14;
                    return 0;
                  }
                  break;
                case 2:
                  param_3[1] = uVar14;
                  *param_3 = 2;
                  return 0;
                case 3:
                  *param_3 = 3;
                  param_3[1] = uVar14;
                  return 0;
                }
              }
            }
            pbVar15 = pbVar15 + 10;
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              return 6;
            }
          } while( true );
        }
      }
    }
  }
  return local_8;
}

