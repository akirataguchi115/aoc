# 608 too low
# 611 too low
# 612 not right
# 613 not right
# 614 not right
# 615 not right
# 616 not right

# 619 not right
# 621 this was right letsgooo
# 622 not right
# 623 not right
# 624 not right
# 625 not right
# 626 too high

# btw this does not work good enough it marks a tad too many levels as unsafe
# and it doesn't halt since i broke it after i tried refactoring next time git
def main(data):
  f = open(data, 'r')
  lines = f.readlines()
  f.close()
  safe_count = 0
  for line in lines:
    report = [int(x) for x in line.split()]
    index = -1
    safe = False
    while index < len(report):
      modified_report = report[:]
      dincreasing = modified_report[0] - modified_report[1]
      diff = modified_report[index] - modified_report[index + 1]
      if index == -1:
        diff = modified_report[0] - modified_report[1]
        if not (dincreasing < 0 and diff < 0) or (dincreasing > 0 and diff > 0) or abs(diff) < 1 or abs(diff) > 3:
          safe = True
          index =+ 1
          break
        continue
      modified_report.pop(index)
      if not (dincreasing < 0 and diff < 0) or (dincreasing > 0 and diff > 0) or abs(diff) < 1 or abs(diff) > 3:
        safe = False
        break
      index += 1
    if safe: safe_count += 1

  print(safe_count)

main('2.txt') 
main('2.test')