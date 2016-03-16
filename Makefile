.PHONY: clean All

All:
	@echo "----------Building project:[ Assignment07 - Debug ]----------"
	@cd "Assignment07" && "$(MAKE)" -f  "Assignment07.mk"
clean:
	@echo "----------Cleaning project:[ Assignment07 - Debug ]----------"
	@cd "Assignment07" && "$(MAKE)" -f  "Assignment07.mk" clean
