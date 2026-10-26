
int FUN_008d8510(undefined1 *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint uVar5;
  int local_c;
  byte local_5;
  
  uVar2 = *param_3;
  local_c = 0;
  puVar3 = (undefined4 *)FUN_008baee0(uVar2,0x18,&local_c);
  if (local_c != 0) {
    return local_c;
  }
  if (param_1 + 4 <= param_2) {
    *(undefined1 *)(puVar3 + 1) = *param_1;
    *(ushort *)((int)puVar3 + 6) = CONCAT11(param_1[1],param_1[2]);
    *(undefined1 *)((int)puVar3 + 5) = param_1[3];
    pbVar4 = param_1 + 4;
    puVar3[3] = pbVar4 + (param_3[1] - param_3[0x25]);
    local_5 = *(byte *)((int)puVar3 + 5) & 1;
    puVar3[2] = 3;
    if (local_5 != 0) {
      puVar3[2] = 5;
    }
    if ((*(byte *)((int)puVar3 + 5) & 2) != 0) {
      puVar3[2] = puVar3[2] + 1;
    }
    uVar5 = (uint)*(byte *)(puVar3 + 1);
    if (pbVar4 + uVar5 * puVar3[2] <= param_2) {
      if (*(char *)(puVar3 + 1) == '\0') {
        FUN_008b9f80(uVar2,puVar3);
        return local_c;
      }
      if (local_5 == 0) {
        puVar3[4] = (uint)*pbVar4 << 0x10 | (uint)(byte)param_1[5];
        puVar3[5] = (uint)pbVar4[(uVar5 - 1) * puVar3[2]] << 0x10 |
                    (uint)(pbVar4 + (uVar5 - 1) * puVar3[2])[1];
      }
      else {
        pbVar1 = pbVar4 + (uVar5 - 1) * puVar3[2] + 2;
        puVar3[4] = CONCAT22(CONCAT11(*pbVar4,param_1[5]),CONCAT11(param_1[6],param_1[7]));
        puVar3[5] = CONCAT22(CONCAT11(pbVar1[-2],pbVar1[-1]),CONCAT11(*pbVar1,pbVar1[1]));
      }
      *puVar3 = 0;
      *(undefined4 **)param_3[0x23] = puVar3;
      param_3[0x23] = puVar3;
      param_3[0x21] = param_3[0x21] + (uint)*(byte *)(puVar3 + 1);
      return 0;
    }
  }
  FUN_008b9f80(uVar2,puVar3);
  return 8;
}

